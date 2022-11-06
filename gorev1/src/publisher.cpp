#include "ros/ros.h"
#include "std_msgs/String.h"
#include <std_msgs/Int32.h>
#include "gorev1/Num.h"
#include <sstream>


int main(int argc, char **argv)
{

  ros::init(argc, argv, "talker");

  ros::NodeHandle n;

  ros::Publisher chatter_pub = n.advertise<gorev1::Num>("chatter", 10);

  gorev1::Num msg;

  int a;
  int b;

  std::cout << "ilk açıyı giriniz: ";
  std::cin >> a;
  msg.num1 = a;
  std::cout << "ikinci açıyı giriniz: ";
  std::cin >> b;
  msg.num2 = b;

  while(ros::ok){
    ros::Rate loop_rate(10);
    chatter_pub.publish(msg);
    loop_rate.sleep();
  }

  return 0;
}

