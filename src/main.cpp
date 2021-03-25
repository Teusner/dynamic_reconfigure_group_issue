#include <ros/ros.h>

#include <dynamic_reconfigure/server.h>
#include <dynamic_reconfigure_group_issue/ExampleConfig.h>

void callback(dynamic_reconfigure_group_issue::ExampleConfig &config, uint32_t level) {
  ROS_INFO("Reconfigure Request: %f", config.double_param);                             // Work everytime
  ROS_INFO("Reconfigure Request via groups: %f", config.groups.my_group.double_param);  // Don't work with the first call to set the default value
}

int main(int argc, char **argv) {
  ros::init(argc, argv, "dynamic_tutorials");

  dynamic_reconfigure::Server<dynamic_reconfigure_group_issue::ExampleConfig> server;
  dynamic_reconfigure::Server<dynamic_reconfigure_group_issue::ExampleConfig>::CallbackType f;

  f = boost::bind(&callback, _1, _2);
  server.setCallback(f);

  ROS_INFO("Spinning node");
  ros::spin();
  return 0;
}
