//
// Created by MisThe on 2023/9/25.
//

#include "../Include/Core/Graphic/Pipeline/Pipeline/ForwardPipeline.h"
#include "../Include/Core/Graphic/Pipeline/Pipeline/ForwardFeatures/OpaqueFeature.h"
#include "../Include/Core/Graphic/Pipeline/Pipeline/ForwardFeatures/SkyboxFeature.h"
#include "../Include/Core/Graphic/Pipeline/Pipeline/ForwardFeatures/TransparentFeature.h"
#include "../Include/General/Queue.h"

REFLECT_REGISTER(ForwardPipeline) /* NOLINT */

ForwardPipeline::ForwardPipeline() {
    //创建相关feature
    this->features.push(cast<GraphicFeature>(new_ptr<OpaqueFeature>()));
    this->features.push(cast<GraphicFeature>(new_ptr<SkyboxFeature>()));
    this->features.push(cast<GraphicFeature>(new_ptr<TransparentFeature>()));
}

void ForwardPipeline::Invoke(std::shared_ptr<RenderData> data) {
    data->core->BeginFrame();
    Queue::Iterator<var<GraphicFeature>>(this->features, [&data](var<GraphicFeature>& feature) {
        feature->Invoke(data);
    });
    data->core->EndFrame();
}