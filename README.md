# Mouse Node Package - `mouse_node_EmreKolbakir` 🐭🎮

## Introduction 📖

This ROS package, `mouse_node_EmreKolbakir`, is designed to interface with a computer mouse device 🖱️, read its input events directly from the device file, and publish them to a ROS topic. This package is particularly useful for robotics projects that may need to use a standard mouse as an input device for control, navigation, or data gathering.

## How It Works 🤔

The package contains two primary components:

- **Publisher Node (`mouse_publisher`)**: This node opens the mouse device file (typically `/dev/input/mouse0` or `/dev/input/mouse2`), reads the raw data, and publishes it to a ROS topic named `/mouse_node`.

- **Subscriber Node (`mouse_subscriber`)**: This node subscribes to the `/mouse_node` topic and logs the incoming mouse data to the console. This demonstrates how one might use the mouse data in a larger ROS-based application.

## Getting Started 🚀

### Prerequisites 📋

Ensure you have a ROS distribution (such as ROS Melodic or Noetic) installed on your system. You also need to have permissions to read from the mouse device file on your system (`/dev/input/mouseX`).

### Installation 🛠️

1. Navigate to the `src` directory of your catkin workspace:
    ```bash
    cd ~/catkin_ws/src
    ```

2. Clone this repository into your workspace:
    ```bash
    git clone https://github.com/EmreKolbakir/mouse_node_EmreKolbakir.git
    ```

3. Go back to your catkin workspace root and compile the package:
    ```bash
    cd ~/catkin_ws
    catkin_make
    ```

4. Source your workspace to make the package available to ROS:
    ```bash
    source devel/setup.bash
    ```

### Usage 🖥️

1. Start the ROS master server:
    ```bash
    roscore
    ```

2. Open a new terminal and run the publisher to start publishing mouse data:
    ```bash
    rosrun mouse_node_EmreKolbakir mouse_publisher
    ```

3. Open another terminal and run the subscriber to start receiving and logging mouse data:
    ```bash
    rosrun mouse_node_EmreKolbakir mouse_subscriber
    ```

Ensure each step is run in a separate terminal or use `&` to send processes to the background.

## Understanding the Package 🧐

- The mouse data is read as an array of unsigned integers, each representing a different aspect of the mouse's current state, such as movement and button presses.

- The `mouse_publisher` node opens the mouse device file, reads this data continuously, and publishes it to the `/mouse_node` topic.

- The `mouse_subscriber` node listens to the `/mouse_node` topic and outputs the received data to the console for real-time observation.


Project maintained by [@EmreKolbakir](https://github.com/EmreKolbakir) ✨.
