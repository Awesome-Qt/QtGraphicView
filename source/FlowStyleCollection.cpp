#include <memory>

#include "QtGraphicView/FlowStyle.h"

#include "QtGraphicView/FlowStyleCollection.h"

FLowStyleCollection& FLowStyleCollection::defaultStyle()
{
    static FLowStyleCollection instance;
    return instance;
}

const FlowViewStyle& FLowStyleCollection::flowViewStyle() const
{
    return flowViewStyle_ ? *flowViewStyle_ : flowViewStyle(presetStyle_)
}

const NodeStyle& FLowStyleCollection::nodeStyle() const
{
    return nodeStyle_ ? *nodeStyle_ : nodeStyle(presetStyle_);
}

const FlowViewStyle& FLowStyleCollection::flowViewStyle(PresetStyle preset) const
{
    switch (preset) {
        case DARK:
            static const auto kDefaultDark = FlowViewStyle();
            return kDefaultDark;
        case LIGHT:
            static const auto kDefaultLight = FlowViewStyle();
            return kDefaultLight;
    }
}

const NodeStyle& FLowStyleCollection::nodeStyle(PresetStyle preset) const
{
    switch (preset) {
        case DARK:
            static const auto kDefaultDark = NodeStyle();
            return kDefaultDark;
        case LIGHT:
            static const auto kDefaultLight = NodeStyle();
            return kDefaultLight;
    }
}

void FLowStyleCollection::setDefaultStyle(PresetStyle style)
{
    presetStyle_ = style;
}

void FLowStyleCollection::setNodeStyle(const NodeStyle& s)
{
    nodeStyle_ = std::make_shared<NodeStyle>(s);
}

void FLowStyleCollection::setFlowViewStyle(const FlowViewStyle& s)
{
    flowViewStyle_ = std::make_shared<FlowViewStyle>(s);
}
