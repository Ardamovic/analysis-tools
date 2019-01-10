#ifndef Analysis_Tools_BaseAnalyser_h
#define Analysis_Tools_BaseAnalyser_h 1

// -*- C++ -*-
//
// Package:    Analysis/Tools
// Class:      Analysis
// 
/**\class BaseAnalyser BaseAnalyser.cc Analysis/Tools/src/BaseAnalyser.cc

 Description: A base class for analyser

 Implementation:
     [Notes on implementation]
*/
//
// Original Author:  Roberval Walsh
//         Created:  6 Sep 2018
//
//

// system include files
#include <memory>
#include <vector>
#include <string>
// 
// user include files
#include "boost/program_options.hpp"

#include "Analysis/Tools/interface/Analysis.h"
#include "Analysis/Tools/interface/Config.h"
#include "TFile.h"
#include "TH1.h"
#include "TH2.h"


namespace po = boost::program_options;


//
// class declaration
//

namespace analysis {
   namespace tools {

      class BaseAnalyser {
         
         public:
            /// constructors
            BaseAnalyser();
            BaseAnalyser(int argc, char * argv[]);
            /// desctructor
           ~BaseAnalyser();
           
         
            // ----------member data ---------------------------
         protected:
            // main objects
            std::shared_ptr<Analysis> analysis_;
            std::shared_ptr<Config>   config_;
            
            // selection
            int cutflow_;
            
            // seed value
            int seed_;
            
            // output root file
            std::shared_ptr<TFile> hout_;
            std::map<std::string, std::shared_ptr<TH1F> > h1_;
         
         private:
            
            // name of the executable 
            std::string exe_;
            
         public:
            // Gets
            /// returns pointer to Analysis object
            std::shared_ptr<Analysis> analysis();
            /// returns pointer to Config object
            std::shared_ptr<Config>   config();
            
            /// number of events to be processed
            int nEvents();
            
            
            /// returns 1D histograms
            std::map<std::string, std::shared_ptr<TH1F> > histograms();
            /// returns a given histogram
            std::shared_ptr<TH1F> histogram(const std::string &);
            
            /// print out the cut flow
            void cutflow();
            
            // Actions
            /// event entry to be readout and processed
            virtual bool event(const int &);
            /// create n histograms of a given type
            virtual void histograms(const std::string &, const int &);
               
            /// others
            int  seed();
            int  seed(const std::string &);
            void seed(const int &);

      };
   }
}

#endif  // Analysis_Tools_BaseAnalyser_h
