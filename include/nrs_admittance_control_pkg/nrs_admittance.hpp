#ifndef NRS_ADMITTANCE_CONTROL_HPP
#define NRS_ADMITTANCE_CONTROL_HPP

class NRS_admittance_control
{
private:
    double adm_1D_Perror[3] = {0,};
    double adm_1D_Ferror[3] = {0,};
    double adm_1D_M = 1;
    double adm_1D_D = 1;
    double adm_1D_K = 0;
    double adm_1D_A, adm_1D_B, adm_1D_C;
    double adm_1D_dt;
    double xc;

public:
    NRS_admittance_control(double sampling_time);
    ~NRS_admittance_control() {}

    bool adm_1D_MDK(double Mass, double Damping, double Stiffness);
    double adm_1D_control(double xd, double Fd, double Fext);
};

#endif
