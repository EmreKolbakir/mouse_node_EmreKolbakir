#include "ros/ros.h"
#include "std_msgs/UInt8MultiArray.h"

// Callback function that will be called when a new message is received on the
// "/mouse_node" topic
void mouseCallback(const std_msgs::UInt8MultiArray::ConstPtr& msg)
{
    ROS_INFO_STREAM("Mouse data received: ");
    // Iterate through the received data and print each byte
    for (int i = 0; i < msg->data.size(); ++i) {
        std::cout << (int)msg->data[i] << " ";
    }
    std::cout << std::endl;
}

int main(int argc, char **argv)
{
    // Initialize the ROS node with the name "mouse_subscriber"
    ros::init(argc, argv, "mouse_subscriber");
    ros::NodeHandle nh;

    // Create a subscriber object that subscribes to the "/mouse_node" topic
    // The mouseCallback function is called when new data is received
    ros::Subscriber sub = nh.subscribe("/mouse_node", 1000, mouseCallback);

    // Enter a loop that processes callbacks and keeps the node running
    ros::spin();

    return 0;
}
