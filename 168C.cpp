#include<bits/stdc++.h>
using namespace std;
int main()
{
	cout<<setprecision(10);
	double a, b, h, m;
	cin>>a>>b>>h>>m;
	// 12 hours of the hour hand sweeps 360 degrees
	// So h hours will sweep h*360/12 + m*30/60
	// m*30/60 bcoz as hour hand moves, the minute hand also moves.
	// Between any two minutes there is an angle of 30 degree.
	// We hv to find how many degrees out of the 30 degrees the minute hand has moved.
	double deg_H=((h*360)/12)*(M_PI/180.0) + ((m*30)/60)*(M_PI/180.0);

	// minute hand sweeps 360 degrees in 60 minutes.
	// So m minutes will sweep m*360/60 degrees.
	double deg_M=((m*360)/60)*(M_PI/180.0);

	// Finding coordinates of the minute hand and hour hand
	double hours_x=a*cos(deg_H);
	double hours_y=a*sin(deg_H);
	double min_x=b*cos(deg_M);
	double min_y=b*sin(deg_M);

	// Apply distance formula
	double res=sqrt((hours_x-min_x)*(hours_x-min_x) + (hours_y-min_y)*(hours_y-min_y));
	cout<<res;
	return 0;
}