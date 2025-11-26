# TTS_Leonardo

Talker is a text-to-speech (TTS) library that converts text into spoken audio. It supports multiple TTS engines and voices.

## Features

- Uses gTTS and ElevenLabs APIs for high-quality TTS
- Saves generated audio to MP3 files for reuse 
- Supports multiple languages and voices
- Caches audio files to avoid generating duplicates
- Falls back to offline pyttsx3 as a failsafe

## Usage 

Import the Talker class:

```python
from talker import Talker

#gTTS - language (you can find them here https://gtts.readthedocs.io/en/latest/module.html#module-gtts.tts) and "" (no api needed)
ja = Talker("ja", "", False)

#ElevenLabs - voice id (Note not voice name, like Laura, but voice id, that is alphanumeric) and api (this are not working examples)
it = Talker("jX####affa####d0Q2", "afkjaj#####ajkfkfajnka###", False)

it.talk("Ciao")

#Other exaples can be found inside the file Main.py

```

The text will be converted to speech and played back immediately (A little delay is present if is not already in the database).

You can also specify:

- voice - Language/voice code
- api - API key for ElevenLabs, or empty string to use gTTS
- temp - Whether to delete the audio file after playing (False saves it)

## Notes

The main difference between the TTS services is the quality of the result.

1. Elevenlabs is the best.
2. gTTS is good.
3. pyttsx3 is enough.

Elevenlabs needs an API key to work, which is easy to obtain and free (with a maximum number of characters per month).

gTTS is good, and also it is possible to read in a language different from the message. For example is possible to emulate a japanese person that is reading a script in english. This is impossible with elevenlabs because it chooses the language by reading the message, so if you want an elevenlabs voice to speak, for exaple, japanese the message sould be written in japanese (kanji).

pyttsx3 is local (offline), the result is a robotic voice, but is understendable. This is important because if, for example an error message needs to be heard but there is no internet connection and is not present in the database pyttsx3 is going to work (automatic failsave).

The class Main is an example.


### Credits
Talker was created by TTT357C (Thomas Causetti).
