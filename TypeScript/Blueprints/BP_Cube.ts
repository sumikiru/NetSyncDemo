import * as UE from "ue";
import {$ref, blueprint} from "puerts";

const uclass = UE.Class.Load("/Game/Blueprints/HotReloadTest/BP_Cube.BP_Cube_C");
const jsClass = blueprint.tojs<typeof UE.Game.Blueprints.HotReloadTest.BP_Cube.BP_Cube_C>(uclass);

interface TS_Cube extends UE.Game.Blueprints.HotReloadTest.BP_Cube.BP_Cube_C {}
class TS_Cube implements TS_Cube {
    /*ReceiveBeginPlay(): void {
        console.log("This message is from BP_Cube");
    }*/

    ReceiveTick(DeltaSeconds: number) {
        this.K2_AddActorWorldRotation(
            new UE.Rotator(0, 0, DeltaSeconds * 100),
            false,
            $ref<UE.HitResult>(),
            false);
    }

    TS_Bigger() : void {
        this.SetActorScale3D(UE.Vector.OneVector.op_Multiply(2));
        UE.KismetSystemLibrary.PrintString(this, "成功", true, true);
    }
}

blueprint.mixin(jsClass, TS_Cube);