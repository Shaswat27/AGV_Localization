#include <ros/ros.h>
#include <roboteq/GetSpeed.h>

//###THIS PROGRAM IS FOR GETING THE MOTOR ENCODER READING THROUGH THE TERMINAL MANUALLY BY JUST RUNNING THE EXECUTABLE

int main(int argc, char **argv) {
    ros::init(argc, argv, "motor_speed_client");

//@Rahul:Again why the <1> is used for exiting the program.NEED TO <CHECK THE ERROR CODES>

    if (argc != 1) {
        ROS_INFO("usage: motor_speed_client");
        return 1;
    }

    ros::NodeHandle n;
    ros::ServiceClient client = n.serviceClient<roboteq::GetSpeed > ("motor_speed");
    eklavya_roboteq::GetSpeed srv;
    if (client.call(srv)) {
        ROS_INFO("Speed response : %ld, %ld", (long int) srv.response.left_speed, (long int) srv.response.right_speed);
    } else {
        ROS_ERROR("Failed to call service get speed");
        return 1;
    }

    return 0;
}
