#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <tf/transform_listener.h>

void counterCallback(const sensor_msgs::LaserScan::ConstPtr& msg){
    ROS_INFO("LaserScan (val,angle)=(%f,%f", msg->range_min,msg->angle_min);
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "laser_listener");
    ros::NodeHandle n;
    ros::Subscriber sub = n.subscribe("chatter", 1000, chatterCallback);
    ros::spin();
    return 0;
}