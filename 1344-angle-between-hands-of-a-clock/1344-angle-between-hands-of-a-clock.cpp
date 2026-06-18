class Solution {
public:
    double angleClock(int hour, int minutes) {
         // hour hand har min mai move krta h 
         //   60 min - 5 mark ,,    1 min - 60/5 ie 1/12 ... 
double hourpos = (hour)* 5 +  minutes / 12.0;

              // eg 3:40 - 3*5 + 40/12 = = 15 + 3.3333
  //      = 18.3333
//                 
 double minpos = minutes;
 double diff = abs(hourpos - minpos);
 double angle = diff*6;
 return min(angle , 360-angle);

    }
};