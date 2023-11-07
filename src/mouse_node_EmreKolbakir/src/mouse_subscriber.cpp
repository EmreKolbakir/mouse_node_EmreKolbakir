#include "ros/ros.h"
#include "std_msgs/UInt8MultiArray.h"

void mouseCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg)
{
    ROS_INFO_STREAM("Mouse data received: ");
    for (int i = 0; i < msg->data.size(); ++i) {
        std::cout << (int)msg->data[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    ros::init(argc, argv, "mouse_subscriber");
    ros::NodeHandle nh;

    ros::Subscriber sub = nh.subscribe("/mouse_node", 1000, mouseCallback);

    ros::spin();

    return 0;
}
