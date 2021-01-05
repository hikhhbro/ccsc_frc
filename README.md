## 低盘

* [ ] 测试手动
* [ ] 测试里程计  下地正方向跑动  和世界坐标里程计
* [ ] 自动pid  不带电机，查看值正不正确
* [ ]


## 运动模型
https://www.sohu.com/a/193593445_715708

Welcome to the 2020-Infinite_Recharge wiki!

Software We Track
National Instruments
https://www.ni.com/en-us/support/downloads/drivers/download.frc-game-tools.html#333285 Driver station, roboRio…

WPILib (with VS Code and extensions)
https://github.com/wpilibsuite/allwpilib/releases

You may want git Bash too: https://gitforwindows.org/

Navx
https://www.kauailabs.com/navx-mxp/

Rev Robotics Spark Max
https://www.revrobotics.com/sparkmax-software/

CTRE Talon SRX / Phoenix Tuner for Pneumatics and PDP
http://www.ctr-electronics.com/talon-srx.html#product_tabs_technical_resources

CTRE Falcon FX
Same installer as above, firmware updates here: http://www.ctr-electronics.com/control-system/motor-control/talon-fx.html#product_tabs_technical_resources

Limelight
https://limelightvision.io/pages/downloads

FRC Radio Configuration
https://docs.wpilib.org/en/latest/docs/getting-started/getting-started-frc-control-system/radio-programming.html (2020 uses same firmware as 2019, but good to have link in case we need to reflash)


## 电机上位机
https://github.com/CrossTheRoadElec/Phoenix-Releases/releases
CTRE.Phoenix.Framework.Windows.v5.19.1.0.zip

## 注意精度问题

## 传感器采样
Velocity Measurement Filter
The Talon SRX measures the velocity of all supported sensor types as well as the current position. Every 1ms a velocity sample is measured and inserted into a rolling average.

The velocity sample is measured as the change in position at the time-of-sample versus the position sampled 100ms-prior-to-time-of-sample. The rolling average is sized for 64 samples. Though these settings can be modified, the (100ms, 64 samples) parameters are default.
默认100ms 滑动平均64  默认传感器速率为1ms



## 抬升机构

If we measure a motor output of 7% to keep position, then our java code for Arbitrary Feed Forward with Motion Magic would look like this:

double feedforward = 0.07;
_motorcontroller.set(ControlMode.MotionMagic, targetPos, DemandType.ArbitraryFee

使用操持输出模式