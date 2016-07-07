  #include "../interface/PUReweight.h"

  #include <iostream>
  #include <cstdlib>

float PUReweight::weight(int MC, int target, int input) {

  if (theType == NONE) return 1.0;

  else if (theType == RUN2ANALYSIS) {

    if        (MC==25 && target==25) {
      if (input < 52) 
        return hT2015_MC25ns_Data25ns.at(input) ;
      else 
        // In case nPU is out-of data-profile binning,
        // use weight from last bin
        return hT2015_MC25ns_Data25ns.at(51) ;
    } else if (MC==25 && target==50) {
      return hT2015_MC25ns_Data50ns.at(input) ;
    } else if (MC==50 && target==25) {
      return hT2015_MC50ns_Data25ns.at(input) ; 
    } else if (MC==50 && target==50) {
      return hT2015_MC50ns_Data50ns.at(input) ; 
    } else if (MC==2016 && target==26) {
      return hT2016_MCSpring16_Data2c6fb.at(input) ; 
    } else if (MC==2016 && target==40) {
      return hT2016_MCSpring16_Data4c0fb.at(input) ; 
    } else{
      std::cout << "ERROR: PUReweight: " << MC << " " << target << std::endl;
      abort();
    }
  
  }

  else if (theType == RUN1ANALYSIS) {

    if        (MC==2011 && target==2011) {
      return hT2011.at(input) ;
    } else if (MC==2012 && target==2012) {
      return hT2012.at(input) ;
    } else{
      std::cout << "ERROR: PUReweight: " << MC << " " << target << std::endl;
      abort();
    }

  } 

  else return 0 ;

}

PUReweight::PUReweight(Type type) : 
theType(type) {

  // RUN2ANALYSIS MC Spring2016 target Data 2.6/fb
  double npuSpring16_2c6fb[100] ; 
  npuSpring16_2c6fb[0] = 1.10942e-05;
  npuSpring16_2c6fb[1] = 8.7385e-05;
  npuSpring16_2c6fb[2] = 0.000235451;
  npuSpring16_2c6fb[3] = 0.000460293;
  npuSpring16_2c6fb[4] = 0.00053997;
  npuSpring16_2c6fb[5] = 0.000643108;
  npuSpring16_2c6fb[6] = 0.000806518;
  npuSpring16_2c6fb[7] = 0.00409823;
  npuSpring16_2c6fb[8] = 0.0103187;
  npuSpring16_2c6fb[9] = 0.0119524;
  npuSpring16_2c6fb[10] = 0.0130906;
  npuSpring16_2c6fb[11] = 0.0161581;
  npuSpring16_2c6fb[12] = 0.0221365;
  npuSpring16_2c6fb[13] = 0.030481;
  npuSpring16_2c6fb[14] = 0.0388027;
  npuSpring16_2c6fb[15] = 0.044809;
  npuSpring16_2c6fb[16] = 0.0478983;
  npuSpring16_2c6fb[17] = 0.0476594;
  npuSpring16_2c6fb[18] = 0.0442376;
  npuSpring16_2c6fb[19] = 0.0389583;
  npuSpring16_2c6fb[20] = 0.0327539;
  npuSpring16_2c6fb[21] = 0.026543;
  npuSpring16_2c6fb[22] = 0.0207051;
  npuSpring16_2c6fb[23] = 0.015336;
  npuSpring16_2c6fb[24] = 0.0107381;
  npuSpring16_2c6fb[25] = 0.00707373;
  npuSpring16_2c6fb[26] = 0.00440416;
  npuSpring16_2c6fb[27] = 0.00259124;
  npuSpring16_2c6fb[28] = 0.00145504;
  npuSpring16_2c6fb[29] = 0.000788986;
  npuSpring16_2c6fb[30] = 0.00041218;
  npuSpring16_2c6fb[31] = 0.000210234;
  npuSpring16_2c6fb[32] = 0.000106008;
  npuSpring16_2c6fb[33] = 5.39633e-05;
  npuSpring16_2c6fb[34] = 2.92773e-05;
  npuSpring16_2c6fb[35] = 1.8728e-05;
  npuSpring16_2c6fb[36] = 1.48676e-05;
  npuSpring16_2c6fb[37] = 1.45913e-05;
  npuSpring16_2c6fb[38] = 1.64934e-05;
  npuSpring16_2c6fb[39] = 1.99875e-05;
  npuSpring16_2c6fb[40] = 2.50058e-05;
  npuSpring16_2c6fb[41] = 3.2628e-05;
  npuSpring16_2c6fb[42] = 4.34942e-05;
  npuSpring16_2c6fb[43] = 5.97589e-05;
  npuSpring16_2c6fb[44] = 8.26555e-05;
  npuSpring16_2c6fb[45] = 0.000118052;
  npuSpring16_2c6fb[46] = 0.000166901;
  npuSpring16_2c6fb[47] = 0.000239219;
  npuSpring16_2c6fb[48] = 0.000347361;
  npuSpring16_2c6fb[49] = 0.000507212;
  npuSpring16_2c6fb[50] = 0.000796241;
  npuSpring16_2c6fb[51] = 0.00109752;
  npuSpring16_2c6fb[52] = 0.00161868;
  npuSpring16_2c6fb[53] = 0.00267864;
  npuSpring16_2c6fb[54] = 0.00377844;
  npuSpring16_2c6fb[55] = 0.00701859;
  npuSpring16_2c6fb[56] = 0.00848053;
  npuSpring16_2c6fb[57] = 0.016081;
  npuSpring16_2c6fb[58] = 0.0324173;
  npuSpring16_2c6fb[59] = 0.0348507;
  npuSpring16_2c6fb[60] = 0;
  npuSpring16_2c6fb[61] = 0;
  npuSpring16_2c6fb[62] = 0;
  npuSpring16_2c6fb[63] = 0;
  npuSpring16_2c6fb[64] = 0;
  npuSpring16_2c6fb[65] = 0;
  npuSpring16_2c6fb[66] = 0;
  npuSpring16_2c6fb[67] = 0;
  npuSpring16_2c6fb[68] = 0;
  npuSpring16_2c6fb[69] = 0;
  npuSpring16_2c6fb[70] = 0;
  npuSpring16_2c6fb[71] = 0;
  npuSpring16_2c6fb[72] = 0;
  npuSpring16_2c6fb[73] = 0;
  npuSpring16_2c6fb[74] = 0;
  npuSpring16_2c6fb[75] = 0;
  npuSpring16_2c6fb[76] = 0;
  npuSpring16_2c6fb[77] = 0;
  npuSpring16_2c6fb[78] = 0;
  npuSpring16_2c6fb[79] = 0;
  npuSpring16_2c6fb[80] = 0;
  npuSpring16_2c6fb[81] = 0;
  npuSpring16_2c6fb[82] = 0;
  npuSpring16_2c6fb[83] = 0;
  npuSpring16_2c6fb[84] = 0;
  npuSpring16_2c6fb[85] = 0;
  npuSpring16_2c6fb[86] = 0;
  npuSpring16_2c6fb[87] = 0;
  npuSpring16_2c6fb[88] = 0;
  npuSpring16_2c6fb[89] = 0;
  npuSpring16_2c6fb[90] = 0;
  npuSpring16_2c6fb[91] = 0;
  npuSpring16_2c6fb[92] = 0;
  npuSpring16_2c6fb[93] = 0;
  npuSpring16_2c6fb[94] = 0;
  npuSpring16_2c6fb[95] = 0;
  npuSpring16_2c6fb[96] = 0;
  npuSpring16_2c6fb[97] = 0;
  npuSpring16_2c6fb[98] = 0;
  npuSpring16_2c6fb[99] = 0;
  for(int k = 0 ; k < 100 ; ++k)
    hT2016_MCSpring16_Data2c6fb.push_back(npuSpring16_2c6fb[k]) ;
  
  // RUN2ANALYSIS MC Spring2016 target Data 4.0/fb
  double npuSpring16_4c0fb[100] ; 
  npuSpring16_4c0fb[0] = 8.7422e-06;
  npuSpring16_4c0fb[1] = 7.63583e-05;
  npuSpring16_4c0fb[2] = 0.00033404;
  npuSpring16_4c0fb[3] = 0.000636716;
  npuSpring16_4c0fb[4] = 0.000771597;
  npuSpring16_4c0fb[5] = 0.000792934;
  npuSpring16_4c0fb[6] = 0.000892549;
  npuSpring16_4c0fb[7] = 0.00352036;
  npuSpring16_4c0fb[8] = 0.00888222;
  npuSpring16_4c0fb[9] = 0.0119397;
  npuSpring16_4c0fb[10] = 0.0160619;
  npuSpring16_4c0fb[11] = 0.0213887;
  npuSpring16_4c0fb[12] = 0.0281328;
  npuSpring16_4c0fb[13] = 0.0370348;
  npuSpring16_4c0fb[14] = 0.0459453;
  npuSpring16_4c0fb[15] = 0.0516731;
  npuSpring16_4c0fb[16] = 0.0539392;
  npuSpring16_4c0fb[17] = 0.0534552;
  npuSpring16_4c0fb[18] = 0.0506146;
  npuSpring16_4c0fb[19] = 0.0462617;
  npuSpring16_4c0fb[20] = 0.040696;
  npuSpring16_4c0fb[21] = 0.0346134;
  npuSpring16_4c0fb[22] = 0.0284331;
  npuSpring16_4c0fb[23] = 0.0222798;
  npuSpring16_4c0fb[24] = 0.0165486;
  npuSpring16_4c0fb[25] = 0.0115209;
  npuSpring16_4c0fb[26] = 0.00747978;
  npuSpring16_4c0fb[27] = 0.00448272;
  npuSpring16_4c0fb[28] = 0.00248583;
  npuSpring16_4c0fb[29] = 0.00128658;
  npuSpring16_4c0fb[30] = 0.000621414;
  npuSpring16_4c0fb[31] = 0.000285809;
  npuSpring16_4c0fb[32] = 0.00012797;
  npuSpring16_4c0fb[33] = 5.75304e-05;
  npuSpring16_4c0fb[34] = 2.77107e-05;
  npuSpring16_4c0fb[35] = 1.60887e-05;
  npuSpring16_4c0fb[36] = 1.20626e-05;
  npuSpring16_4c0fb[37] = 1.15813e-05;
  npuSpring16_4c0fb[38] = 1.30154e-05;
  npuSpring16_4c0fb[39] = 1.57539e-05;
  npuSpring16_4c0fb[40] = 1.97052e-05;
  npuSpring16_4c0fb[41] = 2.57109e-05;
  npuSpring16_4c0fb[42] = 3.42733e-05;
  npuSpring16_4c0fb[43] = 4.70898e-05;
  npuSpring16_4c0fb[44] = 6.51323e-05;
  npuSpring16_4c0fb[45] = 9.30244e-05;
  npuSpring16_4c0fb[46] = 0.000131517;
  npuSpring16_4c0fb[47] = 0.000188504;
  npuSpring16_4c0fb[48] = 0.000273719;
  npuSpring16_4c0fb[49] = 0.000399681;
  npuSpring16_4c0fb[50] = 0.000627436;
  npuSpring16_4c0fb[51] = 0.00086484;
  npuSpring16_4c0fb[52] = 0.00127551;
  npuSpring16_4c0fb[53] = 0.00211076;
  npuSpring16_4c0fb[54] = 0.0029774;
  npuSpring16_4c0fb[55] = 0.00553063;
  npuSpring16_4c0fb[56] = 0.00668263;
  npuSpring16_4c0fb[57] = 0.0126717;
  npuSpring16_4c0fb[58] = 0.0255447;
  npuSpring16_4c0fb[59] = 0.0274622;
  npuSpring16_4c0fb[60] = 0;
  npuSpring16_4c0fb[61] = 0;
  npuSpring16_4c0fb[62] = 0;
  npuSpring16_4c0fb[63] = 0;
  npuSpring16_4c0fb[64] = 0;
  npuSpring16_4c0fb[65] = 0;
  npuSpring16_4c0fb[66] = 0;
  npuSpring16_4c0fb[67] = 0;
  npuSpring16_4c0fb[68] = 0;
  npuSpring16_4c0fb[69] = 0;
  npuSpring16_4c0fb[70] = 0;
  npuSpring16_4c0fb[71] = 0;
  npuSpring16_4c0fb[72] = 0;
  npuSpring16_4c0fb[73] = 0;
  npuSpring16_4c0fb[74] = 0;
  npuSpring16_4c0fb[75] = 0;
  npuSpring16_4c0fb[76] = 0;
  npuSpring16_4c0fb[77] = 0;
  npuSpring16_4c0fb[78] = 0;
  npuSpring16_4c0fb[79] = 0;
  npuSpring16_4c0fb[80] = 0;
  npuSpring16_4c0fb[81] = 0;
  npuSpring16_4c0fb[82] = 0;
  npuSpring16_4c0fb[83] = 0;
  npuSpring16_4c0fb[84] = 0;
  npuSpring16_4c0fb[85] = 0;
  npuSpring16_4c0fb[86] = 0;
  npuSpring16_4c0fb[87] = 0;
  npuSpring16_4c0fb[88] = 0;
  npuSpring16_4c0fb[89] = 0;
  npuSpring16_4c0fb[90] = 0;
  npuSpring16_4c0fb[91] = 0;
  npuSpring16_4c0fb[92] = 0;
  npuSpring16_4c0fb[93] = 0;
  npuSpring16_4c0fb[94] = 0;
  npuSpring16_4c0fb[95] = 0;
  npuSpring16_4c0fb[96] = 0;
  npuSpring16_4c0fb[97] = 0;
  npuSpring16_4c0fb[98] = 0;
  npuSpring16_4c0fb[99] = 0;
  for(int k = 0 ; k < 100 ; ++k)
    hT2016_MCSpring16_Data4c0fb.push_back(npuSpring16_4c0fb[k]) ;

  // RUN2ANALYSIS MC 25ns target Data25ns
  // from https://twiki.cern.ch/twiki/bin/view/CMS/PileupJSONFileforData#2015_Pileup_JSON_Files 13-10-2015 done with mb=69mb Lumi=1260
  double npuWinter15_25ns[52] ; 
  npuWinter15_25ns[0] = 0.09672924 ;
  npuWinter15_25ns[1] = 0.6018639 ;
  npuWinter15_25ns[2] = 0.1982618 ;
  npuWinter15_25ns[3] = 0.04426294 ;
  npuWinter15_25ns[4] = 0.01555679 ;
  npuWinter15_25ns[5] = 0.002250036 ;
  npuWinter15_25ns[6] = 0.001632626 ;
  npuWinter15_25ns[7] = 0.003994533 ;
  npuWinter15_25ns[8] = 0.00634282 ;
  npuWinter15_25ns[9] = 0.006385341 ;
  npuWinter15_25ns[10] = 0.006274029 ;
  npuWinter15_25ns[11] = 0.005998706 ;
  npuWinter15_25ns[12] = 0.004751215 ;
  npuWinter15_25ns[13] = 0.003026687 ;
  npuWinter15_25ns[14] = 0.001546196 ;
  npuWinter15_25ns[15] = 0.0006348245 ;
  npuWinter15_25ns[16] = 0.0002329903 ;
  npuWinter15_25ns[17] = 0.0001029755 ;
  npuWinter15_25ns[18] = 6.678185e-05 ;
  npuWinter15_25ns[19] = 4.525077e-05 ;
  npuWinter15_25ns[20] = 2.500376e-05 ;
  npuWinter15_25ns[21] = 1.071974e-05 ;
  npuWinter15_25ns[22] = 3.512034e-06 ;
  npuWinter15_25ns[23] = 8.834002e-07 ;
  npuWinter15_25ns[24] = 1.682074e-07 ;
  npuWinter15_25ns[25] = 2.370267e-08 ;
  npuWinter15_25ns[26] = 2.504465e-09 ;
  npuWinter15_25ns[27] = 1.951381e-10 ;
  npuWinter15_25ns[28] = 1.149427e-11 ;
  npuWinter15_25ns[29] = 4.720787e-13 ;
  npuWinter15_25ns[30] = 1.194543e-14 ;
  npuWinter15_25ns[31] = 2.021363e-16 ;
  npuWinter15_25ns[32] = 1.841988e-18 ;
  npuWinter15_25ns[33] = 0 ;
  npuWinter15_25ns[34] = 0 ;
  npuWinter15_25ns[35] = 0 ;
  npuWinter15_25ns[36] = 0 ;
  npuWinter15_25ns[37] = 0 ;
  npuWinter15_25ns[38] = 0 ;
  npuWinter15_25ns[39] = 0 ;
  npuWinter15_25ns[40] = 0 ;
  npuWinter15_25ns[41] = 0 ;
  npuWinter15_25ns[42] = 0 ;
  npuWinter15_25ns[43] = 0 ;
  npuWinter15_25ns[44] = 0 ;
  npuWinter15_25ns[45] = 0 ;
  npuWinter15_25ns[46] = 0 ;
  npuWinter15_25ns[47] = 0 ;
  npuWinter15_25ns[48] = 0 ;
  npuWinter15_25ns[49] = 0 ;
  npuWinter15_25ns[50] = 0 ;
  npuWinter15_25ns[51] = 0 ; 
   
  // from https://twiki.cern.ch/twiki/bin/view/CMS/ExoDiBosonResonancesRun2#PU_weights old recipe 27-10-2015 done with mb=80mb
  /*
  double npuWinter15_25ns[52] ; 
  npuWinter15_25ns[0] = 4.8551E-07; 
  npuWinter15_25ns[1] = 1.74806E-06;
  npuWinter15_25ns[2] = 3.30868E-06;
  npuWinter15_25ns[3] = 1.62972E-05;
  npuWinter15_25ns[4] = 4.95667E-05;
  npuWinter15_25ns[5] = 0.000606966;
  npuWinter15_25ns[6] = 0.003307249;
  npuWinter15_25ns[7] = 0.010340741;
  npuWinter15_25ns[8] = 0.022852296;
  npuWinter15_25ns[9] = 0.041948781;
  npuWinter15_25ns[10] = 0.058609363;
  npuWinter15_25ns[11] = 0.067475755;
  npuWinter15_25ns[12] = 0.072817826;
  npuWinter15_25ns[13] = 0.075931405;
  npuWinter15_25ns[14] = 0.076782504;
  npuWinter15_25ns[15] = 0.076202319;
  npuWinter15_25ns[16] = 0.074502547;
  npuWinter15_25ns[17] = 0.072355135;
  npuWinter15_25ns[18] = 0.069642102;
  npuWinter15_25ns[19] = 0.064920999;
  npuWinter15_25ns[20] = 0.05725576;
  npuWinter15_25ns[21] = 0.047289348;
  npuWinter15_25ns[22] = 0.036528446;
  npuWinter15_25ns[23] = 0.026376131;
  npuWinter15_25ns[24] = 0.017806872;
  npuWinter15_25ns[25] = 0.011249422;
  npuWinter15_25ns[26] = 0.006643385;
  npuWinter15_25ns[27] = 0.003662904;
  npuWinter15_25ns[28] = 0.001899681;
  npuWinter15_25ns[29] = 0.00095614;
  npuWinter15_25ns[30] = 0.00050028;
  npuWinter15_25ns[31] = 0.000297353;
  npuWinter15_25ns[32] = 0.000208717;
  npuWinter15_25ns[33] = 0.000165856;
  npuWinter15_25ns[34] = 0.000139974;
  npuWinter15_25ns[35] = 0.000120481;
  npuWinter15_25ns[36] = 0.000103826;
  npuWinter15_25ns[37] = 8.88868E-05;
  npuWinter15_25ns[38] = 7.53323E-05;
  npuWinter15_25ns[39] = 6.30863E-05;
  npuWinter15_25ns[40] = 5.21356E-05;
  npuWinter15_25ns[41] = 4.24754E-05;
  npuWinter15_25ns[42] = 3.40876E-05;
  npuWinter15_25ns[43] = 2.69282E-05;
  npuWinter15_25ns[44] = 2.09267E-05;
  npuWinter15_25ns[45] = 1.5989E-05;
  npuWinter15_25ns[46] = 4.8551E-06;
  npuWinter15_25ns[47] = 2.42755E-06;
  npuWinter15_25ns[48] = 4.8551E-07;
  npuWinter15_25ns[49] = 2.42755E-07;
  npuWinter15_25ns[50] = 1.21378E-07;
  npuWinter15_25ns[51] = 4.8551E-08;
  */
  for(int k = 0 ; k < 52 ; ++k)
    hT2015_MC25ns_Data25ns.push_back(npuWinter15_25ns[k]) ;

  // RUN2ANALYSIS  MC 25ns target Data50ns
  for(int k = 0 ; k < 300 ; ++k)
    hT2015_MC25ns_Data50ns.push_back(1.) ;

  // RUN2ANALYSIS  MC 50ns target Data25ns
  for(int k = 0 ; k < 300 ; ++k)
    hT2015_MC50ns_Data25ns.push_back(1.) ;

  // RUN2ANALYSIS  MC 50ns target Data50ns
  for(int k = 0 ; k < 300 ; ++k)
    hT2015_MC50ns_Data50ns.push_back(1.) ;

  // RUN1ANALYSIS 2011 taken from HZZ4l FIXME _check_
  float w2011[50];
  w2011[0]= 0.212929;
  w2011[1]= 0.0208114;
  w2011[2]= 0.0584048;
  w2011[3]= 0.538898;
  w2011[4]= 1.357;
  w2011[5]= 1.49913;
  w2011[6]= 1.42247;
  w2011[7]= 1.35904;
  w2011[8]= 1.29946;
  w2011[9]= 1.27925;
  w2011[10]= 1.37845;
  w2011[11]= 1.71246;
  w2011[12]= 1.5291;
  w2011[13]= 1.35234;
  w2011[14]= 1.22215;
  w2011[15]= 1.0155;
  w2011[16]= 1.01137;
  w2011[17]= 0.395465;
  w2011[18]= 0.230984;
  w2011[19]= 0.109883;
  w2011[20]= 0.0433739;
  w2011[21]= 0.0111497;
  w2011[22]= 0.00408801;
  w2011[23]= 0.00115678;
  w2011[24]= 0.000365505;
  w2011[25]= 0.000112391;
  w2011[26]= 3.83894e-05;
  w2011[27]= 1.60651e-05;
  w2011[28]= 4.81412e-06;
  w2011[29]= 1.39717e-06;
  w2011[30]= 1.92368e-06;
  w2011[31]= 4.10748e-06;
  w2011[32]= 2.33157e-05;
  w2011[33]= 4.0181e-05;
  w2011[34]= 4.87786e-05;
  w2011[35]= 0.00194128;
  w2011[36]= 8.97414e-05;
  w2011[37]= 1;
  w2011[38]= 1;
  w2011[39]= 0.000162709;
  w2011[40]= 1;
  w2011[41]= 1;
  w2011[42]= 1;
  w2011[43]= 1;
  w2011[44]= 1;
  w2011[45]= 1;
  w2011[46]= 1;
  w2011[47]= 1;
  w2011[48]= 1;
  w2011[49]= 1;
  for(int k=0 ;k<50 ;++k)
    hT2011.push_back(w2011[k]) ;

  // RUN1ANALYSIS 2012 FIXME taken from HZZ4l FIXME _check_
  float w2012[240];
  w2012[0]= 1;
  w2012[1]= 1;
  w2012[2]= 0.222451;
  w2012[3]= 0.0658851;
  w2012[4]= 1;
  w2012[5]= 1;
  w2012[6]= 0.150902;
  w2012[7]= 0.202205;
  w2012[8]= 1;
  w2012[9]= 1;
  w2012[10]= 1.50116;
  w2012[11]= 2.79375;
  w2012[12]= 0.198341;
  w2012[13]= 0.246893;
  w2012[14]= 0.28116;
  w2012[15]= 0.449377;
  w2012[16]= 0.553276;
  w2012[17]= 1.48919;
  w2012[18]= 2.15249;
  w2012[19]= 3.62415;
  w2012[20]= 4.33041;
  w2012[21]= 3.57192;
  w2012[22]= 4.99603;
  w2012[23]= 7.79303;
  w2012[24]= 8.04276;
  w2012[25]= 8.05557;
  w2012[26]= 12.9364;
  w2012[27]= 9.9036;
  w2012[28]= 14.6975;
  w2012[29]= 13.3387;
  w2012[30]= 10.9734;
  w2012[31]= 12.6077;
  w2012[32]= 11.5617;
  w2012[33]= 10.8107;
  w2012[34]= 14.5043;
  w2012[35]= 17.8497;
  w2012[36]= 11.8817;
  w2012[37]= 9.6805;
  w2012[38]= 12.2255;
  w2012[39]= 10.1117;
  w2012[40]= 10.2482;
  w2012[41]= 11.5398;
  w2012[42]= 9.35737;
  w2012[43]= 9.90259;
  w2012[44]= 9.19216;
  w2012[45]= 7.57377;
  w2012[46]= 7.94847;
  w2012[47]= 7.15578;
  w2012[48]= 5.63016;
  w2012[49]= 5.35972;
  w2012[50]= 5.05791;
  w2012[51]= 3.35313;
  w2012[52]= 3.60582;
  w2012[53]= 3.35256;
  w2012[54]= 2.49496;
  w2012[55]= 2.28219;
  w2012[56]= 2.21227;
  w2012[57]= 1.76362;
  w2012[58]= 1.68533;
  w2012[59]= 1.62149;
  w2012[60]= 1.34263;
  w2012[61]= 1.30646;
  w2012[62]= 1.21918;
  w2012[63]= 1.10347;
  w2012[64]= 1.08544;
  w2012[65]= 1.0251;
  w2012[66]= 0.907123;
  w2012[67]= 0.905997;
  w2012[68]= 0.869217;
  w2012[69]= 0.816708;
  w2012[70]= 0.76043;
  w2012[71]= 0.714367;
  w2012[72]= 0.679723;
  w2012[73]= 0.665294;
  w2012[74]= 0.609956;
  w2012[75]= 0.586386;
  w2012[76]= 0.548999;
  w2012[77]= 0.521088;
  w2012[78]= 0.4929;
  w2012[79]= 0.453545;
  w2012[80]= 0.44546;
  w2012[81]= 0.406266;
  w2012[82]= 0.378486;
  w2012[83]= 0.347898;
  w2012[84]= 0.337097;
  w2012[85]= 0.313674;
  w2012[86]= 0.291392;
  w2012[87]= 0.283346;
  w2012[88]= 0.25272;
  w2012[89]= 0.244178;
  w2012[90]= 0.228673;
  w2012[91]= 0.211327;
  w2012[92]= 0.19084;
  w2012[93]= 0.179408;
  w2012[94]= 0.169234;
  w2012[95]= 0.157131;
  w2012[96]= 0.143818;
  w2012[97]= 0.140968;
  w2012[98]= 0.124021;
  w2012[99]= 0.118273;
  w2012[100]= 0.109751;
  w2012[101]= 0.0977754;
  w2012[102]= 0.0967206;
  w2012[103]= 0.0870401;
  w2012[104]= 0.0826372;
  w2012[105]= 0.0746777;
  w2012[106]= 0.0698592;
  w2012[107]= 0.0656062;
  w2012[108]= 0.0601853;
  w2012[109]= 0.057892;
  w2012[110]= 0.0517871;
  w2012[111]= 0.0512109;
  w2012[112]= 0.0465423;
  w2012[113]= 0.0403982;
  w2012[114]= 0.0443631;
  w2012[115]= 0.0399185;
  w2012[116]= 0.0338933;
  w2012[117]= 0.0354274;
  w2012[118]= 0.0310775;
  w2012[119]= 0.0261122;
  w2012[120]= 0.0280878;
  w2012[121]= 0.0264014;
  w2012[122]= 0.021299;
  w2012[123]= 0.0245197;
  w2012[124]= 0.0221076;
  w2012[125]= 0.0189236;
  w2012[126]= 0.0202148;
  w2012[127]= 0.0177248;
  w2012[128]= 0.0163634;
  w2012[129]= 0.0188307;
  w2012[130]= 0.0144512;
  w2012[131]= 0.0134599;
  w2012[132]= 0.0143315;
  w2012[133]= 0.0130668;
  w2012[134]= 0.0108666;
  w2012[135]= 0.0162516;
  w2012[136]= 0.0126035;
  w2012[137]= 0.0102154;
  w2012[138]= 0.0154442;
  w2012[139]= 0.00959973;
  w2012[140]= 0.0106827;
  w2012[141]= 0.0146624;
  w2012[142]= 0.0155156;
  w2012[143]= 0.00761674;
  w2012[144]= 0.0187999;
  w2012[145]= 0.0135013;
  w2012[146]= 0.0160794;
  w2012[147]= 0.0180586;
  w2012[148]= 0.00905508;
  w2012[149]= 0.00869858;
  w2012[150]= 0.0193968;
  w2012[151]= 0.0209201;
  w2012[152]= 0.0084405;
  w2012[153]= 0.0407657;
  w2012[154]= 0.0109116;
  w2012[155]= 0.0262218;
  w2012[156]= 0.0104767;
  w2012[157]= 1;
  w2012[158]= 1;
  w2012[159]= 1;
  w2012[160]= 1;
  w2012[161]= 0.00658031;
  w2012[162]= 0.0051814;
  w2012[163]= 1;
  w2012[164]= 1;
  w2012[165]= 1;
  w2012[166]= 1;
  w2012[167]= 1;
  w2012[168]= 1;
  w2012[169]= 1;
  w2012[170]= 1;
  w2012[171]= 1;
  w2012[172]= 1;
  w2012[173]= 1;
  w2012[174]= 1;
  w2012[175]= 1;
  w2012[176]= 1;
  w2012[177]= 1;
  w2012[178]= 1;
  w2012[179]= 1;
  w2012[180]= 1;
  w2012[181]= 1;
  w2012[182]= 1;
  w2012[183]= 1;
  w2012[184]= 1;
  w2012[185]= 1;
  w2012[186]= 1;
  w2012[187]= 1;
  w2012[188]= 1;
  w2012[189]= 1;
  w2012[190]= 1;
  w2012[191]= 1;
  w2012[192]= 1;
  w2012[193]= 1;
  w2012[194]= 1;
  w2012[195]= 1;
  w2012[196]= 1;
  w2012[197]= 1;
  w2012[198]= 1;
  w2012[199]= 1;
  w2012[200]= 1;
  w2012[201]= 1;
  w2012[202]= 1;
  w2012[203]= 1;
  w2012[204]= 1;
  w2012[205]= 1;
  w2012[206]= 1;
  w2012[207]= 1;
  w2012[208]= 1;
  w2012[209]= 1;
  w2012[210]= 1;
  w2012[211]= 1;
  w2012[212]= 1;
  w2012[213]= 1;
  w2012[214]= 1;
  w2012[215]= 1;
  w2012[216]= 1;
  w2012[217]= 1;
  w2012[218]= 1;
  w2012[219]= 1;
  w2012[220]= 1;
  w2012[221]= 1;
  w2012[222]= 1;
  w2012[223]= 1;
  w2012[224]= 1;
  w2012[225]= 1;
  w2012[226]= 1;
  w2012[227]= 1;
  w2012[228]= 1;
  w2012[229]= 1;
  w2012[230]= 1;
  w2012[231]= 1;
  w2012[232]= 1;
  w2012[233]= 1;
  w2012[234]= 1;
  w2012[235]= 1;
  w2012[236]= 1;
  w2012[237]= 1;
  w2012[238]= 1;
  w2012[239]= 1;
  for(int k=0 ;k<240 ;k++)
    hT2012.push_back(w2012[k]) ;
}

PUReweight::~PUReweight() {}

