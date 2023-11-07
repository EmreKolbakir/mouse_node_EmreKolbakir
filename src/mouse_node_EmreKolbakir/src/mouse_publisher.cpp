#include "ros/ros.h"
#include "std_msgs/UInt8MultiArray.h"
#define MOUSEFILE "/dev/input/mouse2" // Define the path to the mouse device file
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv) {
    // Initialize the ROS node with the name "mouse_publisher"
    ros::init(argc, argv, "mouse_publisher");
    ros::NodeHandle nh;

    // Create a publisher object that can advertise messages of type UInt8MultiArray
    // on the topic "/mouse_node" with a queue size of 1000
    ros::Publisher mouse_pub = nh.advertise<std_msgs::UInt8MultiArray>("/mouse_node", 1000);
    std_msgs::UInt8MultiArray mouse_msg;

    // Open the mouse device file for reading
    int fd = open(MOUSEFILE, O_RDONLY);
    if (fd == -1) {
        // If the file cannot be opened, log an error and exit
        ROS_ERROR_STREAM("Error opening mouse input file: " << MOUSEFILE);
        return 1;
    }

    char data[3]; // Buffer to store the read mouse data
    // Main loop that runs until the node is shutdown
    while (ros::ok()) {
        // Read 3 bytes of data from the mouse file
        if(read(fd, data, sizeof(data)) > 0) {
            // Clear the previous message data
            mouse_msg.data.clear();
            // Push each byte of the mouse data into the message
            for (int i = 0; i < 3; ++i) {
                mouse_msg.data.push_back(data[i]);
            }
            // Publish the message on the "/mouse_node" topic
            mouse_pub.publish(mouse_msg);
            // Allow ROS to process incoming messages
            ros::spinOnce();
        }
    }
    // Close the mouse device file before exiting
    close(fd);
    return 0;
}
