# 🎵 Music Player

A simple, cross-platform music player built with [Raylib](https://www.raylib.com/). This lightweight application allows you to browse and play your local music library directly from a clean, interactive interface.

---

## ✨ Features

- **🖥️ Full-Screen Support** - Automatically adapts to any screen resolution
- **⚡ Minimalist UI** - Clean black interface with intuitive controls
- **🎶 Multi-Format Support** - Plays `.mp3`, `.ogg`, and `.wav` files
- **💿 Auto-Directory Creation** - Creates a `music/` folder if missing on first run
- **🔄 Automatic Playlist Management** - Handles song completion gracefully
- **⏱️ Real-Time Playback Stats** - Shows current playback time and total duration

---

## 📦 Requirements

### Runtime Dependencies

- **Windows**: [Raylib](https://github.com/raysan5/raylib) (DLL included with build)
- Any modern Windows version (7/8/10/11)

### Development Dependencies (if building from source)

- C++ compiler supporting C++98 or newer
- Raylib headers and library files

---

## 🚀 Installation

### Option 1: Download Prebuilt Executable

1. Go to the [Releases](https://github.com/USER/MUSIC_player-main/releases) page
2. Download the latest `.exe` file
3. Double-click `main.exe` to launch the application
4. Place your music files in the `music/` folder (created automatically if needed)

### Option 2: Build from Source

1. Clone the repository:
   ```bash
   git clone https://github.com/USER/MUSIC_player-main.git
   cd MUSIC_player-main
   ```

2. Compile with a C++ compiler:
   ```bash
   g++ main.cpp -o main.exe -lraylib
   ```

3. Run the executable and follow on-screen instructions

---

## 📁 Project Structure

```
MUSIC_player-main/
│
├── main.cpp              # Main source code (Raylib-based)
├── main.exe             # Built application
└── music              # Music files directory
    
```

---

## 🎮 Usage

1. **Launch** the application by double-clicking `main.exe`
2. **Wait** for the player to scan your music library (creates folder if needed)
3. **Click** on any song title in the list to start playback
4. **Monitor** real-time stats including:
   - Current track name
   - Elapsed time
   - Total track duration

### 🎯 Interaction Guide

- **Mouse Click**: Select and play a track from the list
- **ESC / Window Close Button**: Exit application

---

## ⚙️ Configuration

### Debug Mode

Set `debug = true` in `main.cpp` to enable diagnostic output:

```cpp
bool debug = false; // change to true to debug
```

This displays internal state information during runtime.

### Screen Resolution

The player automatically matches your desktop resolution. To override, uncomment and modify:

```cpp
// const int screenWidth = 3440;
// const int screenHeight = 1440;
int screenWidth = GetScreenWidth();
int screenHeight = GetScreenHeight();
```

---

## 📝 Supported Formats

| Format | Extension | Status |
|--------|-----------|--------|
| MP3    | `.mp3`    | ✅ Full Support |
| OGG    | `.ogg`    | ✅ Full Support |
| WAV    | `.wav`    | ✅ Full Support |

*Note: Use semicolons to separate multiple formats in `LoadDirectoryFilesEx()` when building.*

---

## 🛠️ Development Notes

### Technical Stack

- **Language**: C++ (C++98 compatible)
- **Library**: [Raylib](https://www.raylib.com/) - Simple and easy-to-use utility functions for game programming, made by [Ramón Santamaria](https://twitter.com/raysan5)
- **Target FPS**: 165 frames per second

### File Loading System

The player uses `LoadDirectoryFilesEx()` to scan the `music/` directory with support for multiple audio formats simultaneously.

---

## 🐛 Known Issues & Limitations

- Currently limited to single-track playback (no queue/playlist management)
- No built-in volume control
- UI text could benefit from localization options

### Future Enhancements

- [x] Add pause/resume functionality
- [ ] Implement playlist shuffling
- [ ] New ui
- [x] Volume controls

---

## 📄 License



Feel free to modify and redistribute. Just give credit!

---

## 👤 Credits

- **Development**: Built with ❤️ using Raylib
- **Design Philosophy**: Inspired by the "better commit" principles for clean, maintainable code

---

## 📬 Contributing

Want to improve this player? Here's how you can help:

1. **Fork** the repository
2. Create a feature branch (`git checkout -b feature/amazing-feature`)
3. Commit your changes following good practices:
   ```bash
   git commit -m "Add amazing new feature"
   ```
4. Push to the branch (`git push origin feature/amazing-feature`)
5. Open a Pull Request

### 🎯 Commit Guidelines

Keep commits focused and descriptive:

- Use imperative mood ("Add feature", not "Added feature")
- Keep subjects under 50 characters when possible
- Add body only for complex changes or context that isn't obvious from the diff

---

## 🔗 Resources

- [Raylib Official Website](https://www.raylib.com/)
- [Raylib GitHub Repository](https://github.com/raysan5/raylib)
- [C++ Standard (C++98)](https://en.wikipedia.org/wiki/C%2B%2B98)

---

**Enjoy your music! 🎧🎶**
