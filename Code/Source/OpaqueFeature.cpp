//
// Created by MisThe on 2023/9/25.
//

#include "../Include/Core/Graphic/Pipeline/Pipeline/ForwardFeatures/OpaqueFeature.h"
#include "../Include/General/Container/Queue.h"

REFLECT_REGISTER(OpaqueFeature) /* NOLINT */

void OpaqueFeature::Invoke(std::shared_ptr<RenderData> data) {
//    RenderTextureDescribe describe;
//    describe.width = 1920;
//    describe.height = 1080;
//    describe.depth = 24;
//    describe.formats = { ColorFormat::RGBA32, ColorFormat::RGBA32, ColorFormat::RGBA32 };
//    var<RenderTexture> renderTexture = data->core->GetTemporary(describe);
//    data->core->SetTarget(renderTexture);
    Color color;
    color.SetColor(1,2,3,4);
    data->core->ClearTarget(color, true, true);

    data->core->DrawRenderers(data->renderers);
    Queue::Iterator<var<Renderer>>(data->renderers, [&data](var<Renderer> &renderer) {
        data->core->DrawRenderer(renderer);
    });
//    data->core->PutTemporary(renderTexture);
}
