#ifndef FLOW_STYLE_COLLECTION_H
#define FLOW_STYLE_COLLECTION_H

#pragma once

#include <QColor>
#include <QPixmap>
#include <memory>

#include "QtGraphicView/QtGraphicView_export.hpp"

struct FlowViewStyle;
struct NodeStyle;

enum PresetStyle
{
    LIGHT,
    DARK,
};

class QTGRAPHICVIEW_EXPORT FLowStyleCollection
{
  public:
    FLowStyleCollection(const FLowStyleCollection&) = default;
    FLowStyleCollection(FLowStyleCollection&&) = delete;
    FLowStyleCollection& operator=(const FLowStyleCollection&) = default;
    FLowStyleCollection& operator=(FLowStyleCollection&&) = delete;
    virtual ~FLowStyleCollection() = default;

    [[nodiscard]] const FlowViewStyle& flowViewStyle() const;

    [[nodiscard]] const NodeStyle& nodeStyle() const;

    [[nodiscard]] const FlowViewStyle& flowViewStyle(PresetStyle preset) const;

    [[nodiscard]] const NodeStyle& nodeStyle(PresetStyle preset) const;

    void setDefaultStyle(PresetStyle style);

    void setNodeStyle(const NodeStyle&);

    void setFlowViewStyle(const FlowViewStyle&);

    static FLowStyleCollection& defaultStyle();

  private:
    FLowStyleCollection() = default;
    std::shared_ptr<FlowViewStyle> flowViewStyle_ {};
    std::shared_ptr<NodeStyle> nodeStyle_ {};
    PresetStyle presetStyle_ {};
};

#endif
