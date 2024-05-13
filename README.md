# Weather-Application

Overview

The Weather Application is a user-friendly application that provides accurate weather infomation to the user through a user-friendly interface. The weather application 
can forecast the weather for the users location up to 7 days and provide the temperature and rain chance for every one of those days. When the app is first opened the app is able to locate the users location and provide weather information for their respective location and users can view all weather information for all Australian capital cities. This application leverages various APIs and data sources to deliver real-time weather updates.a


Features
- Current Weather: View current weather conditions including temperature and rain chance
- Forecast: Provide a detailed weather forecast infromation for the next 7 days including the high and low temperatures and rain chance
- Saved Locations: Save frequently visited locations to save locations list to easily access their weather information
- Delete Saved Locations: Delete a location off the location list to choose other cities to put on the list.a

Technlogies Used
- Programming Language: C++
- APIs: [openweathermap api]
- Libraries:[SFML, curl, nlohmann json]

## Instructions
To build:
- Make a build directory and within it run 'cmake ..', then when it is finished, run 'make'
- Navigate to the bin directory within build
- run the 'weather' executable

To use:
- After running, the weather for the user's location is displayed, click on the displayed location to enter the location menu.
- Within the location menu is the location list, by clicking the add button, up to five locations chosen from Austrlian capital cities can be added to the list.
- Clicking a location within the list will display the weather information for that locaiton.
- Locations can be deleted by pressing the bin icon button.
- Locations can be reordered by dragging and dropping them in the desired position.
- The location list is saved between runs of the application.

## Preview images
<div align="center">
  <img src="https://github.com/liamblaschka/image-repo/blob/main/Weather-Application/user_location.png">
  <p>First the weather for the user's location (based on their IP) is displayed.</p>
  
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
