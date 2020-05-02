# OpenDFB
## 背景
DirectFB官方已经不再维护，但目前还有不少用户使用DirectFB，该组件从某种程度上可以说是业界事实标准，之所以这么流行原因是DirectFB天生就是针对嵌入式设备而设计，以最小的资源来实现了最高的硬件加速性。如今IOT设备流行，需要一种在RAM和ROM占用均小图形显示组件，所以该项目从DirectFB-1.6.3拉出了一个分支，命名OpenDFB，该项目主要是通过对DirectFB代码进行重构和精简，旨在建立一个IOT轻量级设备的显示服务组件。

## 重构思路
OpenDFB定位为IOT设备显示服务组件，因为DirectFB发展多年，一方面存在历史代码导致代码陈旧，另外一方面也存在发展中增加了很多背离最早轻量级设计目标的很多没有用的功能，OpenDFB出现就是为了解决这些问题，主要是通过明确显示服务的目标删除一些没有用的功能，甚至对外接口也会有些调整，目前调整的代码包括：
1. 将directfb内部C++代码统一整改成纯C代码，避免代码膨胀，保持代码简洁；(done)
2. 删除历史遗留的半吊子组件，包括++dfb, dvc, fusiondale, fusionsound, voodoo, input hub;  (done)
3. 显示服务需要强化显示功能，对于显示之外的功能进行删除，包括IDirectFBVideoProvider,IFusionSound,IFusionSoundMusicProvider,IWater；（done）
4. 对外接口保留，但内部实现保留最简单实现，建议应用端实现， 包括Image provider, Font/Text. （done）
5. 对于2D接口保留Blitter相关功能，对于其他矢量绘制等功能均删除. （done）
6. 将游离directfb之外的库收编到内部直接编译，包括sawman, divine;（done）
7. 将内核fusion机制使用socket来代替，避免依赖linux内核依赖，方便移植到其他RTOS。（doing）

## 关键规格
OpenDFB关注以下功能，其他功能和规格均会被删除或不会被纳入
1. 提供显示输出功能，包括图形和视频输出；
2. 提供交互输入设备功能，包括按键，触摸，鼠标等输入设备对接；
3. 提供窗口管理功能；
4. 提供2D Blitter图形加速功能，其他绘制接口不会提供；
5. 支持单进程和多进程架构；
