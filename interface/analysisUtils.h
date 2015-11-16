#ifndef analysisUtils_h
#define analysisUtils_h

#include <cstdlib>
#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <map>
#include <unordered_map>
#include <algorithm>
#include <fstream>

#include "RooHist.h"
#include "RooCurve.h"

#include "TH1F.h"
#include "TH2F.h"
#include "THStack.h"
#include "TFile.h"
#include "TMath.h"
#include "TTreeFormula.h"
#include "TText.h"
#include "TLatex.h"
#include "utils.h"
#include "histoUtils.h"
#include "ConfigParser.h"
#include "HistoManager.h"
#include "plotContainer.h"


vector<pair <TString, TCut> > 
addSelection (vector<pair <TString, TCut> > m_cuts, string cut, string tag) ;

std::pair<int, int> leptonsType (int pairType) ;
/*
0 = muons
1 = electrons
2 = taus
true = is isolated
*/
bool isIsolated (int leptonType, float threshold, float isoDeposits, float pT) ; 

void
addHistos (vector<sample> & samples, HistoManager * manager,
           vector<string> & variablesList,
           vector<pair <TString, TCut> > & selections,
           bool isSignal,
           bool isData = false) ;

// implicitly empty 2D list is used --> no 2D filling
counters
fillHistos (vector<sample> & samples, 
            plotContainer & plots,
            vector<string> & variablesList,
            vector<pair <TString, TCut> > & selections,
            float lumi,
            const vector<float> & scale,
            bool isData = false,
            bool isSignal = false,
            int maxEvts = -1, TFile* fOut = 0) ;

counters
fillHistos (vector<sample> & samples, 
            plotContainer & plots,
            vector<string> & variablesList,
            vector<pair<string,string>> & variables2DList,
            vector<pair <TString, TCut> > & selections,
            float lumi,
            const vector<float> & scale,
            bool isData = false,
            bool isSignal = false,
            int maxEvts = -1, TFile* fOut = 0) ;

// create a counter structure from the plotContainer
//counters
//makeCounter (plotContainer & plots, float initEff = 1.0, float initTotNum = 0.0) ; 

vector<THStack *> 
stackHistos (vector<sample> & samples, HistoManager * manager, 
            vector<string> & variablesList,
            vector<pair <TString, TCut> > & selections,
            const string & tag) ;

// --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- --- ---
// utilities to draw data/background plot + legend + ratioplot, return vector of ROOT objects allocated on the heap
std::vector<TObject*> makeStackPlot (plotContainer& dataPlots, plotContainer& bkgPlots, plotContainer& sigPlots,
                                      string varName, string selName,
                                      TCanvas* canvas, std::vector <pair <string, string> > & addInLegend, std::vector <pair <string, string> >& axisTitles,
                                      bool LogY = false, bool makeRatioPlot = true, bool drawLegend = true, bool doShapes = false, bool forceNonNegMin = false, bool drawGrassForData = false,
                                      bool drawSignal = true, bool drawData = true, bool drawMC = true) ;

#endif