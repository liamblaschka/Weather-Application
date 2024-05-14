# Weather-Application

## Description
This is a C++ SFML Weather Application providing weather information for the user's location and the Australian capital cities. The weather information includes the current weather, as well as a 7 day forecast containing the minimum and maximum temperature, and the chance of rain for each day. This application uses the Open Weather Map API to source the real-time weather data.

### Skills demonstrated:
- C++
- Object Oriented Programming
- SFML
- Design of friendly user interface

### Features:
- Current weather
- 7 day forecast
- User location: view weather information of the user's location.
- Saved locations: save up to five locations of Australian capital cities.

## Instructions
### To use:
- After running, the weather for the user's location is displayed, click on the displayed location to enter the location menu.
- Within the location menu is the location list.
- Locations can be added to the list by clicking the add button, where up to five Australian capital cities can be chosen.
- Clicking a location within the list will display the weather information for that locaiton.
- Locations can be deleted by pressing the bin icon button.
- Locations can be reordered by dragging and dropping them in the desired position.
- The location list is saved between runs of the application.

### To build:
- Make a build directory and within it run 'cmake ..' , then when it is finished, run 'make'.
- Navigate to the bin directory within build.
- Run the 'weather' executable.

## Preview
<div align="center">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/user_location.png" width="330" height="450">
  <p>First the weather for the user's location (based on their IP) is displayed.</p>
  <br>
  
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/location_menu.png" width="220" height="300">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/add_locations.png" width="220" height="300">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/delete_locations.png" width="220" height="300">
  <br>
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/reorder_locations.png" width="220" height="300">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/select_location.png" width="220" height="300">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/selected_location.png" width="220" height="300">
  <p>
    The location menu can be opened by clicking the currently displayed location.<br>
    Up to five locations chosen from Australian capital cities can be added to the location list.<br>
    Locations can be removed from the list, and reordered by dragging and dropping.<br>
    A location can be selected by clicking on it.
  </p>

  
</div>
