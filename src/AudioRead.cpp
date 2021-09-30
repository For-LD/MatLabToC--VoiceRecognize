#include "AudioRead.h"


//=======================================================================
namespace examples
{

    //=======================================================================
    void loadAudioFileAndPrintSummary(double audio[16000])
    {
        //---------------------------------------------------------------
        //std::cout << "**********************" << std::endl;
        //std::cout << "Running Example: Load Audio File and Print Summary" << std::endl;
        //std::cout << "**********************" << std::endl << std::endl;
        
        //---------------------------------------------------------------
        // 1. Set a file path to an audio file on your machine
        const std::string filePath = std::string () + "./bin/1.wav";
        
        //---------------------------------------------------------------
        // 2. Create an AudioFile object and load the audio file
        
        AudioFile<float> a;
        bool loadedOK = a.load (filePath);
        
        /** If you hit this assert then the file path above
         probably doesn't refer to a valid audio file */
        assert (loadedOK);
        
        //---------------------------------------------------------------
        // 3. Let's print out some key details

        //std::cout << "Bit Depth: " << a.getBitDepth() << std::endl;
        //std::cout << "Sample Rate: " << a.getSampleRate() << std::endl;
        //std::cout << "Num Channels: " << a.getNumChannels() << std::endl;
        //std::cout << "Length in Seconds: " << a.getLengthInSeconds() << std::endl;

        for (int i = 0; i < a.getNumSamplesPerChannel(); i++)
        {
            for (int channel = 0; channel < a.getNumChannels(); channel++)
            {
                //std::cout << "Length in Seconds: " << a.samples[channel][i] << std::endl;
                audio[i] = a.samples[channel][i];
            }
        }

        std::cout<<a.getNumSamplesPerChannel()<<" "<<a.getNumChannels()<<std::endl;

    }


}
