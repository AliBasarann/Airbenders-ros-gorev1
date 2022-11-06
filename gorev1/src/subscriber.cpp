#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int32.h>
#include "gorev1/Num.h"
#include <vector>


int b = 180;
int count = 0;


void chatterCallback(const gorev1::Num::ConstPtr& msg)
{
  count += 1;
  int result = b - msg->num1 -msg->num2;
  std::cout << "üçüncü açı: " << result << std::endl;
}

int main(int argc, char **argv)
{
  
  ros::init(argc, argv, "listener");

  ros::NodeHandle n;
  ros::Rate loop_rate(10);
  ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
  while(count < 1){
    ros::spinOnce();
    loop_rate.sleep();
  }
  return 0;
}
