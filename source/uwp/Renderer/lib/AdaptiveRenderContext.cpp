#include "pch.h"

#include "AdaptiveRenderContext.h"
#include "AdaptiveFailure.h"
#include "InputItem.h"
#include "Util.h"

using namespace Microsoft::WRL;
using namespace Microsoft::WRL::Wrappers;
using namespace ABI::AdaptiveCards::Uwp;
using namespace ABI::Windows::Foundation;
using namespace ABI::Windows::Foundation::Collections;
using namespace ABI::Windows::UI::Xaml;

namespace AdaptiveCards { namespace Uwp
{
    HRESULT AdaptiveRenderContext::RuntimeClassInitialize() noexcept
    {
        return S_OK;
    }

    HRESULT AdaptiveRenderContext::RuntimeClassInitialize(
        IAdaptiveHostConfig* hostConfig,
        IAdaptiveElementRendererRegistration* elementRendererRegistration,
        IAdaptiveCardResourceResolvers* resourceResolvers,
        IResourceDictionary* overrideDictionary,
        RenderedAdaptiveCard* renderResult) noexcept try
    {
        m_hostConfig = hostConfig;
        m_elementRendererRegistration = elementRendererRegistration;
        m_renderResult = renderResult;
        m_resourceResolvers = resourceResolvers;
        m_overrideDictionary = overrideDictionary;

        return MakeAndInitialize<AdaptiveActionInvoker>(&m_actionInvoker, renderResult);
    } CATCH_RETURN;

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_HostConfig(IAdaptiveHostConfig** value)
    {
        return m_hostConfig.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_ElementRenderers(IAdaptiveElementRendererRegistration** value)
    {
        return m_elementRendererRegistration.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_ActionInvoker(IAdaptiveActionInvoker** value)
    {
        return m_actionInvoker.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_ResourceResolvers(IAdaptiveCardResourceResolvers** value)
    {
        return m_resourceResolvers.CopyTo(value);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::get_OverrideStyles(_COM_Outptr_ IResourceDictionary** overrideDictionary)
    {
        return m_overrideDictionary.CopyTo(overrideDictionary);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::AddFailure(FailureStatusCode failureStatusCode, HSTRING message)
    {
        ComPtr<AdaptiveFailure> error;
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveFailure>(&error, failureStatusCode, message));
        ComPtr<IVector<ABI::AdaptiveCards::Uwp::IAdaptiveFailure*>> vector;
        int statusAsInt = static_cast<int>(failureStatusCode);
        if (IsWarning(statusAsInt))
        {
            RETURN_IF_FAILED(m_renderResult->get_Warnings(&vector));
        }
        else
        {
            RETURN_IF_FAILED(m_renderResult->get_Errors(&vector));
        }
        return (vector->Append(error.Detach()));
    }

    _Use_decl_annotations_
    HRESULT AdaptiveRenderContext::AddInputItem(IAdaptiveCardElement* cardElement, ABI::Windows::UI::Xaml::IUIElement* uiElement)
    {
        ComPtr<IAdaptiveCardElement> localCardElement(cardElement);
        ComPtr<IAdaptiveInputElement> inputElement;
        THROW_IF_FAILED(localCardElement.As(&inputElement));

        ComPtr<IUIElement> localUiElement(uiElement);

        InputItem item(inputElement.Get(), localUiElement.Get());

        auto inputItems = m_renderResult->GetInputItems();

        if (inputItems != nullptr)
        {
            inputItems->push_back(item);
        }
        else
        {
            // Add to Errors
        }

        return S_OK;
    }


}}
