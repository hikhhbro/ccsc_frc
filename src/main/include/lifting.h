#ifndef __LIFTING_H
#define __LIFTING_H
#include "BaseModule.h"
#include "ctre/Phoenix.h"
#include "my_thread.h"
#include <string>
#include <frc/DigitalInput.h>
#ifdef LIFT_DEBUG
#include <frc/smartdashboard/smartdashboard.h>
#endif

class Lifting : public Falcon, public MyThread
{
private:
    enum MOTOR {M1,M2,M_ALL};
    enum STATUS {Stretched,Mid,Shrinked};
    TalonFX* motor[2];
    frc::DigitalInput* reset_sw[M_ALL];
    float smoothing = 0;
    float len_comp = 0;//长度补偿值
    float route = 1100;//mm  伸缩最大行程
    float lift_high = 0;//mm 不能大于最大行程
    float pos_thres = 200;//TODO:待测试
    float speed_thres = 0;//TODO:待测试
    float stretch_speed = 0;//伸出去的速度，不能大于卷簧收缩的速度，单位rpm 
    float shrink_speed = 0;//rpm 0~6000
    float acc = 1500;
    float reset_speed = 100;//rpm 0~6000
    float reset_acc = 0;//rpm
    float reset_output = 0.1;//0~1
    float reset_current_thres = 10;//amps
    float is_reseted = false;
    int reset_error_count = 0;
    int reset_error_thre = (int)(1.0/0.05 * 0.1);//50ms线程运行周期,检测时间阈值为0.1s
    STATUS lift_status = Shrinked;
    std::string error;
public:
    Lifting(int id);
    ~Lifting();
    void set_point(float len);
    bool lift();
    bool stretch_out();
    bool get_reset_key(MOTOR M);
    bool shrink();
    bool reset();
    bool carry_out(float s,float v);
    void run() override;
    bool get_reset_status();
    void disable_motor();
    STATUS get_status();
#ifdef LIFT_DEBUG
    void display() override;
    void debug() override;
#endif
};


#endif