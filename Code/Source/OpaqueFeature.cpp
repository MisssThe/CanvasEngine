//
// Created by MisThe on 2023/9/25.
//

#include "../Include/Core/Graphic/Pipeline/Pipeline/ForwardFeatures/OpaqueFeature.h"
#include "../Include/General/Container/Queue.h"

REFLECT_REGISTER(OpaqueFeature) /* NOLINT */

void OpaqueFeature::Invoke(std::shared_ptr<RenderData> data) {
    data->core->DrawRenderers(data->renderers);
    Queue::Iterator<var<Renderer>>(data->renderers, [&data](var<Renderer> &renderer) {
        data->core->DrawRenderer(renderer);
    });
    //拿取不透明物体并进行排序

//    data->core->DrawRenderers()
}
