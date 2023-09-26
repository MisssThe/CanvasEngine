//
// Created by MisThe on 2023/9/25.
//

#include "../Include/Core/Graphic/Pipeline/Pipeline/ForwardPipeline.h"

REFLECT_REGISTER(ForwardPipeline) /* NOLINT */

ForwardPipeline::ForwardPipeline() {
    //条件相关feature
}

void ForwardPipeline::Invoke(std::shared_ptr<RenderData> data) {
    data->core->BeginFrame();
    data->core->EndFrame();
}