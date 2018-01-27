/*
  ==============================================================================

    This file was auto-generated!

    It contains the basic framework code for a JUCE plugin editor.

  ==============================================================================
*/

#include "PluginProcessor.h"
#include "PluginEditor.h"


//==============================================================================
SvtPluginAudioProcessorEditor::SvtPluginAudioProcessorEditor (SvtPluginAudioProcessor& p)
    : AudioProcessorEditor (&p), processor (p)
{
    setSize (200, 200);
    
    filterMenu.setJustificationType(Justification::centred);
    filterMenu.addItem("Low Pass", 1);
    filterMenu.addItem("Band Pass", 2);
    filterMenu.addItem("High Pass", 3);
    addAndMakeVisible(&filterMenu);
    
    filterCutoffDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    filterCutoffDial.setRange(20.0f, 20000.0f);
    filterCutoffDial.setValue(600.0f);
    filterCutoffDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    filterCutoffDial.setPopupDisplayEnabled(true, true, this);
    addAndMakeVisible(&filterCutoffDial);
    
    filterResDial.setSliderStyle(Slider::SliderStyle::RotaryVerticalDrag);
    filterResDial.setRange(1.0f, 5.0f);
    filterResDial.setValue(2.0f);
    filterResDial.setTextBoxStyle(Slider::NoTextBox, false, 0, 0);
    filterResDial.setPopupDisplayEnabled(true, true, this);
    addAndMakeVisible(&filterResDial);
    
    filterCutoffValue = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "cutoff", filterCutoffDial);
    
    filterResValue = new AudioProcessorValueTreeState::SliderAttachment (processor.tree, "resonance", filterResDial);
    
    filterMenuChoice = new AudioProcessorValueTreeState::ComboBoxAttachment (processor.tree, "filterMenu", filterMenu);
    
    filterCutoffDial.setSkewFactorFromMidPoint(1000.0f);
}

SvtPluginAudioProcessorEditor::~SvtPluginAudioProcessorEditor()
{
}

//==============================================================================
void SvtPluginAudioProcessorEditor::paint (Graphics& g)
{
    //background ui stuff
    Rectangle<int> titleArea (0, 10, getWidth(), 20);
    
    g.fillAll (Colours::black);
    g.setColour(Colours::white);
    g.drawText("Filter", titleArea, Justification::centredTop);
    g.drawText("Cutoff", 46, 70, 50, 25, Justification::centredLeft);
    g.drawText("Resonance", 107, 70, 70, 25, Justification::centredLeft);
    
    Rectangle <float> area (25, 25, 150, 150);
    
    g.setColour(Colours::yellow);
    g.drawRoundedRectangle(area, 20.0f, 2.0f);
}

void SvtPluginAudioProcessorEditor::resized()
{
    //need to come back and dynamically set these...ok for now
    Rectangle<int> area = getLocalBounds().reduced(40);
    
    filterMenu.setBounds(area.removeFromTop(20));
    filterCutoffDial.setBounds (30, 90, 70, 70);
    filterResDial.setBounds (100, 90, 70, 70);
}
