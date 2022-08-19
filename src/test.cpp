#include <stdio.h>
#include <ros/ros.h>
#include <visualization_msgs/Marker.h>
ros::Publisher vis_pub;


void point_marker(double x, double y)
{

	visualization_msgs::Marker marker;
	marker.header.frame_id = "odom";
	marker.header.stamp = ros::Time();
	marker.ns = "my_namespace";
	marker.type = visualization_msgs::Marker::SPHERE;
	marker.action = visualization_msgs::Marker::ADD;
	marker.pose.position.x = x;
	marker.pose.position.y = y;
	marker.pose.position.z = 0;
	marker.pose.orientation.x = 0.0;
	marker.pose.orientation.y = 0.0;
	marker.pose.orientation.z = 0.0;
	marker.pose.orientation.w = 1.0;
	marker.scale.x = 0.1;
	marker.scale.y = 0.1;
	marker.scale.z = 0.1;
	marker.color.a = 1.0; // Don't forget to set the alpha!
	marker.color.r = 0.0;
	marker.color.g = 1.0;
	marker.color.b = 0.0;

	vis_pub.publish( marker );

}



int main(int argc, char** argv)
{
	ros::init(argc, argv, "filter");
	ros::NodeHandle nh;


	vis_pub = nh.advertise<visualization_msgs::Marker>( "visualization_marker", 0 );
	while(ros::ok())
	{
		point_marker(2 , 2);
		point_marker(2 , -2);
		point_marker(-2 , -2);
		point_marker(-2, 2);
		ros::spinOnce();
		
	}

	return 0;
}