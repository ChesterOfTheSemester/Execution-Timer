# Execution Timer 1.0
This C++ script lets you do multiple execution timings.

## Usage Example
To run a full execution timing, `timer` will be called twice. First to define the start-time. And later again to calculate the completion-time. It will be reset and be ready for re-use when it is called again.

```cpp

#include <iostream>
#include "execution_timer.h"

int main()
{
  execution_timer.test(0x01);
  for (int i=0; i<1000000; i++);
  std::cout << "Completed in " << execution_timer.test(0x01) << "ms" << std::endl;

  execution_timer.test(0x02);
  for (int j=0; j<99999999; j++);
  std::cout << "Completed in " << execution_timer.test(0x02) << "ms" << std::endl;

  return 0;
}

```

## Parameters and return value
A unique `uuid` for each timer is necessary for assigning timespans
```cpp
long long time (int uuid = 0)
```

`int uuid` A unique identifier is needed for each timer to store the timelapse values

`@return (long long)` Returns time completion in milliseconds
