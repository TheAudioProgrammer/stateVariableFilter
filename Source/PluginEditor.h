/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#pragma once

#include "../JuceLibraryCode/JuceHeader.h"
#include "PluginProcessor.h"


//==============================================================================
/**
*/
class SvtPluginAudioProcessorEditor  : public AudioProcessorEditor
{
public:
    SvtPluginAudioProcessorEditor (SvtPluginAudioProcessor&);
    ~SvtPluginAudioProcessorEditor();

    //==============================================================================
    void paint (Graphics&) override;
    void resized() override;
    
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterCutoffValue;
    ScopedPointer<AudioProcessorValueTreeState::SliderAttachment> filterResValue;
    
    ScopedPointer<AudioProcessorValueTreeState::ComboBoxAttachment>
    filterMenuChoice;

private:
    Slider filterCutoffDial;
    Slider filterResDial;
    ComboBox filterMenu;
    
    // This reference is provided as a quick way for your editor to
    // access the processor object that created it.
    SvtPluginAudioProcessor& processor;

    JUCE_DECLARE_NON_COPYABLE_WITH_LEAK_DETECTOR (SvtPluginAudioProcessorEditor)
};
