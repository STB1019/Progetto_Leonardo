"""
Talks the given message by using gTTS to convert text to speech.

Saves generated speech to mp3 files in a database folder. 
Checks if a file already exists before generating a new one.
Plays the speech using playsound.

Can specify language, voice ID, whether to delete the file after playing,
and whether to use gTTS vs ElevenLabs.
"""
import time
import pyttsx3
from gtts import gTTS
from playsound import playsound
import os
from elevenlabs import generate, save, Voice
import hashlib

"""
Method that creates an hash without salt, for files names.
"""
def create_hash(input_string):
    
    sha256_hash = hashlib.sha256()

    sha256_hash.update(input_string.encode('utf-8'))

    hash_result = sha256_hash.hexdigest()
    return hash_result


engine = pyttsx3.init()


class Talker:
    
    """
    Constructor, it defines the talker instance
    
    parameters:
    
    - voice: if GTTs is used this parameter is the voice language (ex: ja),
    otherwise if elevenlabs is used is the voice id.
    
    - api: This parameter is used for selecting the service used for the speech
    if it is equals to "" GTTs will be used, otherwise if is equal to a working
    api elevenlabs is going to be used.
    
    - temp: if False the files are saved to the database, otherwise they will be
    temporary.
    
    Note: if there is an error the method will use pyttsx3 as failsave
    """
    def __init__(self, voice = "en", api = "", temp = False) -> None:
        self.voice = voice
        self.api = api
        self.temp = temp
    
    """
    talk() generates an audio file for the given message text 
    using text-to-speech, and plays the audio.

    It supports multiple TTS engines and voices.
    
    - message is the string
    
    it switches between 3 methods of speech, elevenlabs is the best (but needs an account and api to work),
    google is good and pyttsx3 is enough (works offline)
    
    As a failsafe (no database file, no internet connection or error) the method will use pyttsx3
    """
    def talk(self, message):
        
        try:
            
            filename = "database/"+(str(create_hash(message)).upper().strip().replace(" ","").replace(":","")+"0000000000")[0:7]+"_"+str(self.voice).upper()[0:2]+".mp3"
            print(message)
            
            try:
                #Try to play sound from database
                playsound(filename)
                #print("Sound in database")
            except:
                if(self.api == ""):
                    #Google
                    tts = gTTS(str(message),lang=str(self.voice))
                    tts.save(filename)
                else:
                    #Elevenlabs
                    audio = generate(
                        api_key = self.api,
                        text = message,
                        voice = Voice(
                            voice_id=self.voice,
                            ),
                        model="eleven_multilingual_v2"
                    )
                    
                    save(audio,filename)
                    
                time.sleep(0.1)
                playsound(filename)
                #print("No sound in database")
                if(self.temp):
                    os.remove(filename)
                
        except:
            #failsafe
            engine.say(str(message))
            engine.runAndWait()