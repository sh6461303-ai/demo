# Morse Code Translator

A menu-driven Morse Code Translator written in standard C. This repository contains the Milestone 2 console prototype and project notes.

## Features

- English text to Morse code
- Morse code to English text
- Supports A-Z, digits 0-9, and selected punctuation
- Uses spaces between Morse letters and `/` between words
- Menu options to translate, reset, or exit
- Basic handling for unsupported characters and unknown Morse tokens

## Project structure

```
demo/
├── morse_code_translator.c
├── README.md
└── docs/
    └── MILESTONE_2_REPORT.md
```

## Compile and run

### Windows (GCC / MinGW)

```bash
gcc morse_code_translator.c -o morse.exe
.\morse.exe
```

### Linux / macOS

```bash
gcc morse_code_translator.c -o morse
./morse
```

## Example

Input: `HELLO WORLD`

Output:

```
.... . .-.. .-.. --- / .-- --- .-. .-.. -..
```

## Current scope

This is the console-based C prototype. Arduino, buzzer, physical switches, and hardware wiring are not included in this version of the repository because their source files and circuit documentation were not among the available project files.

## Project contributors

- Sanjana Saini
- Nandini Nema

Madhav Institute of Technology & Science, Gwalior.

## Future improvements

- Integrate Arduino hardware, buzzer, and switches
- Add audio/tactile feedback
- Expand character and input support
