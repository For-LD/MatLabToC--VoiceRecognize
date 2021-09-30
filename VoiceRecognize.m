function out = VoiceRecognize(x)%#codegen

out = '';

fs = 16000;

%persistent trainedNet;
persistent spec;

frameDuration = 0.025;
hopDuration = 0.010;
    
frameLength = floor(frameDuration*fs);
hopLength = floor(hopDuration*fs);
waveBuffer = zeros([fs,1]);

numBands = 40;


trainedNet = coder.loadDeepLearningNetwork('commandNet2.mat','trainedNet');

audioBuffer = dsp.AsyncBuffer(fs);

epsil = 1e-6;

write(audioBuffer,x);
waveBuffer(1:end-numel(x)) = waveBuffer(numel(x)+1:end);
waveBuffer(end-numel(x)+1:end) = x;

spec = melSpectrogram(waveBuffer,fs, ...
        'WindowLength',frameLength, ...
        'OverlapLength',frameLength - hopLength, ...
        'FFTLength',512, ...
        'NumBands',numBands, ...
        'FrequencyRange',[50,7000]);
        feature =spec;

feature = log10(feature + epsil);

[YPredicted,probs] = classify(trainedNet,feature);
out = cellstr(YPredicted);
end
