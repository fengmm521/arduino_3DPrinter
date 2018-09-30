//
//
//

#include "Planner.h"
bool NeedOpenLaser_boolArry_Planner[DA_VAL_BUFF_SIZE];


int Times_LinearLnterpolation_intArry_Planner[DA_VAL_BUFF_SIZE];
int T_LinearLnterpolation_int;
int DAValBufferPlanCouter_int_Planner;
int DAValBufferMoveCouter_int_Planner;
int DAValBufferLen_int_Planner;


unsigned short DAValBufferX_ushortPointer_Planner[DA_VAL_BUFF_SIZE][DA_VAL_ARRY_SIZE];//member the Planner planted DAVal
unsigned short DAValBufferY_ushortPointer_Planner[DA_VAL_BUFF_SIZE][DA_VAL_ARRY_SIZE];

float Goal_X_float, Goal_Y_float, Start_X_float, Start_Y_float;
float Dis_X_float, Dis_Y_float;//how far between Goal and Start
float Plus_X_float, Plus_Y_float;//how many long in once LinearLnterpolation
float Plane_X_float, Plane_Y_float;
float RadVal_X_float, RadVal_Y_float;

void PlaneXY_Planner()
//plan the xy monent data and turn to  DAVal
//and put the XY arry address in two pointer
{
	Goal_X_float = GCodeVal_floatArry_Command[0];
	Goal_Y_float = GCodeVal_floatArry_Command[1];

	Dis_X_float = Goal_X_float - Start_X_float;
	Dis_Y_float = Goal_Y_float - Start_Y_float;
	Times_LinearLnterpolation_intArry_Planner[DAValBufferPlanCouter_int_Planner] = sqrt(Dis_X_float*Dis_X_float + Dis_Y_float*Dis_Y_float) / (float)SPEED_XY*(float)CYCLE_LNTERPOLARION;
	if (Times_LinearLnterpolation_intArry_Planner[DAValBufferPlanCouter_int_Planner] != 0) { //calculate all the LinearLnterpolation
		if (Dis_X_float > 0.00001 || Dis_X_float < 0.00001)
			Plus_X_float = (Dis_X_float) / Times_LinearLnterpolation_intArry_Planner[DAValBufferPlanCouter_int_Planner];
		else
			Plus_X_float = 0;

		if (Dis_Y_float > 0.00001 || Dis_Y_float < 0.00001)
			Plus_Y_float = (Dis_Y_float) / Times_LinearLnterpolation_intArry_Planner[DAValBufferPlanCouter_int_Planner];
		else
			Plus_Y_float = 0;

		Plane_X_float = Start_X_float;
		Plane_Y_float = Start_Y_float;

		while (T_LinearLnterpolation_int < Times_LinearLnterpolation_intArry_Planner[DAValBufferPlanCouter_int_Planner])
		{
			Plane_X_float = Plane_X_float + Plus_X_float;
			Plane_Y_float = Plane_Y_float + Plus_Y_float;

			DAValBufferX_ushortPointer_Planner[DAValBufferPlanCouter_int_Planner][T_LinearLnterpolation_int] = DisToDA_X(Plane_X_float, Plane_Y_float);
			DAValBufferY_ushortPointer_Planner[DAValBufferPlanCouter_int_Planner][T_LinearLnterpolation_int] = DisToDA_Y(Plane_Y_float);

			T_LinearLnterpolation_int++;

		}
		T_LinearLnterpolation_int = 0;
		Start_X_float = Goal_X_float;
		Start_Y_float = Goal_Y_float;
	}
	else {//when the dis is evry small
		Times_LinearLnterpolation_intArry_Planner[DAValBufferPlanCouter_int_Planner] = 1;
		DAValBufferX_ushortPointer_Planner[DAValBufferPlanCouter_int_Planner][0] = { DisToDA_X(Goal_X_float, Goal_Y_float) };
		DAValBufferY_ushortPointer_Planner[DAValBufferPlanCouter_int_Planner][0] = { DisToDA_Y(Goal_Y_float) };
		Start_X_float = Goal_X_float;
		Start_Y_float = Goal_Y_float;
	}

	DAValBufferPlanCouter_int_Planner = (DAValBufferPlanCouter_int_Planner + 1) % DA_VAL_BUFF_SIZE;
	DAValBufferLen_int_Planner++;

}

unsigned short DisToDA_X(float x, float y) {
	RadVal_X_float = atan(x / (sqrt(DIS_F_THETA*DIS_F_THETA + y*y) + DIS_XYMOTOR));
	RadVal_Y_float = atan(y / DIS_F_THETA);
	return (atan((x - (DIS_F_THETA*tan(RadVal_X_float)*(1 / cos(RadVal_Y_float) - 1))) / (sqrt(DIS_F_THETA*DIS_F_THETA + y*y) + DIS_XYMOTOR)) / RAD_MG_MAX * 32768 + 32767)* 5/BASE_VOLTAGE;
}

unsigned short DisToDA_Y(float y) {
	return  (RadVal_Y_float / RAD_MG_MAX * 32768 + 32767)*5 / BASE_VOLTAGE;
}
