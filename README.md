# 🕹️ cub3d – 3D Game Development 🎮

Welcome to **cub3d**, an immersive **first-person 3D game** built using **ray-casting**! 🧊 This project demonstrates how to render 3D spaces from 2D maps, creating a game experience that is both fun and technical. Let’s dive into the world of 3D game development! 🌟

## 📝 Project Overview

In **cub3d**, we develop a **3D first-person view game** using **ray-casting** technology, simulating 3D spaces through mathematical rendering. The project includes real-time environment rendering, textures, player movement, and game logic! 🎯

### Features:
- 🔹 **3D first-person view** with ray-casting.
- 🔹 Interactive **movement** and real-time rendering.
- 🔹 Support for bonus levels with enhanced features like **animated blocks**, **minimap** and **doors**.
- 🔹 Uses **MacroLibX** for graphical rendering.

## 🖼️ Game Screenshots

- Minecraft Map with Minimap and Animated Pumpkin Lantern
![Cub3D Gameplay - With Bonus](https://github.com/user-attachments/assets/4dd1f159-c16a-4a2b-a26f-a75cb09299b2)
- Memes Map Without bonues
![Cub3D Gameplay - Without Bonus](https://github.com/user-attachments/assets/c00bf979-05a1-41a1-b564-ff44e4b5abfd)


## 🛠️ Installation & Setup

To get started, follow these steps to set up and run the project:

1. **Clone the repository and the MacroLibX submodule (required for graphical rendering)**:
   ```bash
   git clone https://github.com/mdev9/Cub3d.git
   cd cub3d
   git clone https://github.com/seekrs/MacroLibX.git
   make
   ```

2. **Run the game with a valid map**:
    ```bash
    ./cub3d maps/map.cub
    ```
   - Or run the bonus version with a bonus map:
   
    ```bash
    make bonus
    ./cub3d_bonus maps_bonus/map_bonus.cub
    ```
    
## 🔍 Technologies Used

- C 💻: Core language used to build the game.
- Ray-casting 📡: Rendering technique to simulate 3D spaces.
- MacroLibX 🖼️: Lightweight graphical library for handling the rendering.
- libft 📚: Custom utility functions.

## 🎯 Goals of the Project

- Create a fully functional 3D game using ray-casting.
- Learn about real-time rendering and 3D space simulation.
- Implement efficient player movement and interaction within a 3D world.

Thank you for checking out cub3d! 🎮 Happy gaming and coding! 🚀
