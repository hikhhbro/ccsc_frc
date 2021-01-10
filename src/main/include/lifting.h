#ifndef __LIFTING_H
#define __LIFTING_H
#include "BaseModule.h"
#include "ctre/Phoenix.h"
#include "my_thread.h"
#include <string>
#ifdef LIFT_DEBUG
#include <frc/smartdashboard/smartdashboard.h>
#endif

class Lifting : public Base, public Falcon, public MyThread
{
private:
    enum MOTOR {M1,M2,M_ALL};
    TalonFX* motor[2];
    float smoothing = 0;
    float len_comp = 0;//长度补偿值
    float route = 1100;//mm  伸缩最大行程
    float lift_high = 400;//mm 不能大于最大行程
    float pos_thres = 200;//TODO:待测试
    float speed_thres = 0;//TODO:待测试
    float stretch_speed = 100;//伸出去的速度，不能大于卷簧收缩的速度，单位rpm 
    bool is_stretched = false;
    float reset_speed = 100;//rpm
    float reset_output = 0.1;//0~1
    float reset_current_thres = 10;//amps
    bool is_reseted = false;
    std::string error;
public:
    Lifting(int id);
    ~Lifting();
    void set_point(float len);
    bool lift();
    bool stretch_out();
    bool is_stretch_out();
    bool get_reset_key(MOTOR M);
    bool shrink();
    bool reset();
    bool carry_out(float s,float v);
    void run() override;
    bool get_reset_status();
    bool debug_get_para();
#ifdef LIFT_DEBUG
    void display() override;
    void debug() override;
#endif
};


#endif