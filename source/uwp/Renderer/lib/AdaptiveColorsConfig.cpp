#include "pch.h"
#include "AdaptiveColorsConfig.h"
#include "AdaptiveColorConfig.h"

using namespace Microsoft::WRL;
using namespace ABI::AdaptiveCards::Uwp;

namespace AdaptiveCards { namespace Uwp
{
    HRESULT AdaptiveColorsConfig::RuntimeClassInitialize() noexcept try
    {
        ColorsConfig colorsConfig;
        return RuntimeClassInitialize(colorsConfig);
    } CATCH_RETURN;

    HRESULT AdaptiveColorsConfig::RuntimeClassInitialize(ColorsConfig colorsConfig) noexcept
    {
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveColorConfig>(m_default.GetAddressOf(), colorsConfig.defaultColor));
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveColorConfig>(m_accent.GetAddressOf(), colorsConfig.accent));
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveColorConfig>(m_attention.GetAddressOf(), colorsConfig.attention));
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveColorConfig>(m_dark.GetAddressOf(), colorsConfig.dark));
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveColorConfig>(m_good.GetAddressOf(), colorsConfig.good));
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveColorConfig>(m_light.GetAddressOf(), colorsConfig.light));
        RETURN_IF_FAILED(MakeAndInitialize<AdaptiveColorConfig>(m_warning.GetAddressOf(), colorsConfig.warning));

        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::get_Default(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig** defaultColorConfig)
    {
        return m_default.CopyTo(defaultColorConfig);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::put_Default(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig* colorConfig)
    {
        m_default = colorConfig;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::get_Accent(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig** accentColorConfig)
    {
        return m_accent.CopyTo(accentColorConfig);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::put_Accent(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig* colorConfig)
    {
        m_accent = colorConfig;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::get_Dark(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig** darkColorConfig)
    {
        return m_dark.CopyTo(darkColorConfig);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::put_Dark(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig* colorConfig)
    {
        m_dark = colorConfig;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::get_Light(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig** lightColorConfig)
    {
        return m_light.CopyTo(lightColorConfig);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::put_Light(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig* colorConfig)
    {
        m_light = colorConfig;
        return S_OK;
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::get_Good(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig** goodColorConfig)
    {
        return m_good.CopyTo(goodColorConfig);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::put_Good(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig* colorConfig)
    {
        m_good = colorConfig;
        return S_OK;
    }
    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::get_Warning(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig** warningColorConfig)
    {
        return m_warning.CopyTo(warningColorConfig);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::put_Warning(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig* colorConfig)
    {
        m_warning = colorConfig;
        return S_OK;
    }
    
    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::get_Attention(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig** attentionColorConfig)
    {
        return m_attention.CopyTo(attentionColorConfig);
    }

    _Use_decl_annotations_
    HRESULT AdaptiveColorsConfig::put_Attention(ABI::AdaptiveCards::Uwp::IAdaptiveColorConfig* colorConfig)
    {
        m_attention = colorConfig;
        return S_OK;
    }
}
}
