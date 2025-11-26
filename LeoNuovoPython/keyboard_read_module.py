import os
import time

class Module:
    def __init__(self):
        self.name = "KEY"
        self.file_path = "key.txt"
        
    def read(self):
        # Wait for a short time before checking the file
        time.sleep(0.05)  # Check every 10 milliseconds
        
        # Open and read the content of the file
        with open(self.file_path, 'r') as file:
            content = file.read()
        
        # If the file is not empty
        if(content!=""):
            # Open the file in write mode to clear its contents
            with open(self.file_path, 'w') as file:
                cont = content
                content = ""
                return cont  # Return the original content
        
        # If the file is empty, return None
        return None
