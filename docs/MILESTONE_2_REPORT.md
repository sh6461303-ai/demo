# Milestone 2: Core Module, Prototyping and Implementation

## Introduction
The Morse Code Translator converts English text into Morse code and decodes Morse code into readable English. Milestone 2 implements the core prototype using standard C.

## Objectives
- Convert supported English letters, digits and punctuation into Morse code.
- Decode Morse sequences into English characters.
- Provide a menu for selecting the conversion direction.
- Allow reset and exit.
- Handle unsupported characters and unknown Morse tokens.

## Core modules
- **User menu:** Text-to-Morse, Morse-to-text, reset and exit.
- **Morse mapping:** Stores supported characters and their Morse patterns.
- **Text-to-Morse:** Converts each input character to uppercase and looks up its pattern.
- **Morse-to-text:** Splits Morse input into tokens and looks up each token.
- **Validation:** Skips unsupported text characters and displays `?` for unknown Morse tokens.

## Prototype design
The current implementation is a console-based C program. One space separates Morse letters and a slash (`/`) separates words.

Example: `HELLO WORLD` becomes:

```
.... . .-.. .-.. --- / .-- --- .-. .-.. -..
```

## Algorithms
### Text to Morse
1. Display the menu and read the user's choice.
2. Read the English text.
3. Convert each character to uppercase.
4. Output `/` for word spaces.
5. Look up each supported character and print its Morse pattern.
6. Warn when a character is unsupported.

### Morse to text
1. Read the Morse input.
2. Split it into tokens using whitespace.
3. Convert `/` into a word space.
4. Find each token in the Morse mapping.
5. Print the matching character, or `?` for an unknown token.

## Sample test cases

| Input | Mode | Expected output |
|---|---|---|
| `HELLO` | Text to Morse | `.... . .-.. .-.. ---` |
| `SOS` | Text to Morse | `... --- ...` |
| `.... . .-.. .-.. ---` | Morse to text | `HELLO` |
| `123` | Text to Morse | `.---- ..--- ...--` |
| `.... .-.-.-` | Morse to text | `H.` |

These are expected outputs; run the program to record actual test results.

## Compile and run

Windows with GCC:
```bash
gcc morse_code_translator.c -o morse.exe
.\morse.exe
```

Linux or macOS:
```bash
gcc morse_code_translator.c -o morse
./morse
```

## Limitations
- Console interface only; no GUI yet.
- Only characters in the mapping table are supported.
- No audio playback or vibration output in this version.
- Morse input requires spaces between letters and `/` between words.

## Future scope
- Integrate Arduino hardware, buzzer and switches.
- Add audio beeps and optional tactile feedback.
- Expand supported symbols and improve malformed-input messages.

## Conclusion
Milestone 2 provides a menu-driven C prototype with two-way translation, character mapping, word separation, reset functionality and basic invalid-input handling.
