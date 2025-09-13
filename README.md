
# ESP32 GPS Sensor

A simple GPS tracking system using ESP32 and NEO-6M GPS module with support for both hardware testing and Wokwi simulation.

## Table of Contents
- [Features](#features)
- [Installation](#installation)
- [Usage](#usage)
- [File Overview](#file-overview)
- [Hardware Setup](#hardware-setup)
- [Wokwi Simulation](#wokwi-simulation)
- [Troubleshooting](#troubleshooting)
- [Contributing](#contributing)
- [License](#license)
- [Contact](#contact)

## Features
- Real-time GPS location tracking (latitude, longitude)
- Altitude and speed measurements
- Date and time from GPS satellites
- Debug mode with raw NMEA data display
- Wokwi simulation support for testing without hardware
- Enhanced error diagnostics and wiring validation

## Installation
Clone the repository and set up the development environment:

```bash
git clone https://github.com/elxecutor/gps-sensor.git
cd gps-sensor
```

Install PlatformIO if you haven't already:
```bash
pip install platformio
```

Build the project:
```bash
platformio run
```

## Usage

### Hardware Deployment
1. Connect your ESP32 and GPS module according to the wiring diagram
2. Upload the firmware:
   ```bash
   platformio run --target upload
   ```
3. Open serial monitor at 115200 baud:
   ```bash
   platformio device monitor --baud 115200
   ```

### Wokwi Simulation
1. Build the project:
   ```bash
   platformio run
   ```
2. Upload `diagram.json`, `wokwi.toml`, and the compiled `.bin` file to [Wokwi.com](https://wokwi.com)
3. Start the simulation and monitor the serial output

## File Overview

```
├── src/
│   └── main.cpp           # Main GPS tracking application
├── diagram.json           # Wokwi circuit diagram
├── wokwi.toml            # Wokwi simulation configuration
├── platformio.ini        # PlatformIO project configuration
└── README.md             # This file
```

## Hardware Setup

### Components Required
- ESP32 DevKit V1
- NEO-6M GPS Module
- Breadboard and jumper wires

### Wiring Connections
| GPS Module |   ESP32 Pin   | Wire Color |
|------------|---------------|------------|
| VCC        | 3.3V (or 5V)  | Red        |
| GND        | GND           | Black      |
| TX         | GPIO 16 (RX2) | Green      |
| RX         | GPIO 17 (TX2) | Blue       |

### Power Requirements
- GPS module may require 5V for optimal performance
- Ensure stable power supply for accurate readings

## Wokwi Simulation

The project includes a complete Wokwi simulation setup:

- **Circuit**: ESP32 DevKit V1 + NEO-6M GPS module
- **Pre-configured location**: San Francisco, CA
- **Features**: Serial monitor integration, realistic GPS data simulation

## Troubleshooting

### Common Issues

**"Location: INVALID" messages:**
- Check wiring connections (most common cause)
- Ensure GPS module has clear view of sky
- Wait 1-5 minutes for satellite lock
- Try 5V power instead of 3.3V (if available)

**No GPS data received:**
- Verify Serial2 connections (GPIO 16/17)
- Check power supply stability
- Ensure correct baud rate (9600 for GPS)

**Serial monitor issues:**
- Use 115200 baud rate for ESP32
- Check USB cable and drivers
- Try different USB port

### Debug Mode
The code includes enhanced debugging that shows:
- Raw NMEA sentences from GPS
- Character processing statistics
- Wiring connection guide
- Checksum validation results

## Contributing
We welcome contributions! Please see our [Contributing Guidelines](CONTRIBUTING.md) and [Code of Conduct](CODE_OF_CONDUCT.md) for details.

## License
This project is licensed under the [MIT License](LICENSE).

## Contact
For questions or support, please open an issue or contact the maintainer via [X](https://x.com/elxecutor/).
