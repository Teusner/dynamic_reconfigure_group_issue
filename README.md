# Issue with dynamic_reconfigure
Minimal example of a problem encountered with dynamic_reconfigure. The problem occurs when the callback function is called for parameters belonging to a group.

## Configuration

This issue was encountered using :
* Ubuntu 18.04
* ROS melodic (version 1.14.10)

## Issue

The problem is visible in the shell below. When we want to set a default value for a parameter belonging to a group, the initialization of this parameter is not possible if we try to access the default value with:

```cpp
config.groups.my_group.double_param
```

But it is quite possible to access this default value via:

```cpp
config.double_param
```

```bash
$> rosrun dynamic_reconfigure_group_issue dynamic_reconfigure_server
[ INFO] [1616676590.655748709]: Reconfigure Request: 3.200000
[ INFO] [1616676590.656599822]: Reconfigure Request via groups: 0.000000
[ INFO] [1616676590.657117207]: Spinning node
[ INFO] [1616676614.801760980]: Reconfigure Request: 4.000000
[ INFO] [1616676614.801850468]: Reconfigure Request via groups: 4.000000
```

This inconsistency is only present at initialization, because we notice that once the value to be reconfigured has been modified, both methods provide the same (and good) value.