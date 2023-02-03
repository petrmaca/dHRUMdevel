#include <stdio.h>
#include "dHRUM.h"

using namespace std;

int main() {
  cout << "Testing the functionalities of single HMunit class and dHRU" << endl;

  params parr;

  vector<pair<numberSel,par_HRUtype>> parsToLoad;

  parsToLoad.push_back(make_pair(2.53, par_HRUtype::B_SOIL));
  parsToLoad.push_back(make_pair(500.0, par_HRUtype::C_MAX));
  parsToLoad.push_back(make_pair(2.30, par_HRUtype::B_EVAP));
  parsToLoad.push_back(make_pair(0.02, par_HRUtype::KS));
  parsToLoad.push_back(make_pair(0.06, par_HRUtype::KF));
  parsToLoad.push_back(make_pair(0.7, par_HRUtype::ADIV));
  parsToLoad.push_back(make_pair(0.60, par_HRUtype::CDIV));
  parsToLoad.push_back(make_pair(0.30, par_HRUtype::SDIV));
  parsToLoad.push_back(make_pair(5.00, par_HRUtype::CAN_ST));
  parsToLoad.push_back(make_pair(5.00, par_HRUtype::STEM_ST));
  parsToLoad.push_back(make_pair(0.50, par_HRUtype::CSDIV));
  parsToLoad.push_back(make_pair(0.25, par_HRUtype::DDFA));
  parsToLoad.push_back(make_pair(150.00, par_HRUtype::RETCAP));

  parr.s_parLoadToCalib(parsToLoad);

  for (auto &  itr : parsToLoad) {
    parr.s_params(itr);
  }
data_HB_1d hdta;
  parr.s_default();
  
  std::cout << "I am here/n";
  
  parr.p_param();
  
  std::cout << "I am here/n";
/*   data_HB_1d hdta;


  hdta.s_initDate(1900,12,31,36526);
  hdta.s_calender();
//    hdta.p_calender();
//    parr.s_params(2.3,parsInfo[0]);
//    parr.s_params(3,parsInfo[1]);*/
  hdata prec{10, 0,4, 0, 10, 1, 0, 1,10,10,20,0,0,0,0,0};
  hdata temp{-10, 0,-4, 0, -10, 0, 0, 1,1,10,10,0,2,2,2,4}; 

  single_HMunit sHRU;
  sHRU.set_paramsToSim(parsToLoad);
  sHRU.set_GStype(gs_STORtype::POW_RES);
  // sHRU.print_GStype();
  sHRU.set_GStype(gs_STORtype::LIN_RES);
 // sHRU.print_GStype();
  sHRU.set_GStype(gs_STORtype::EXP_RES);
//  sHRU.print_GStype();
    for (unsigned i=0;i<1; i++) {
    sHRU.load_data_PT(prec,temp,0.0,1900,1,1);
    sHRU.set_PetVars(50.1,pet_Type::HAMON);
    sHRU.calc_Pet();
    sHRU.run_HB();
    sHRU.print_OutputToFile("./data/tests/printTest.txt");
  } 

// TESTS on PET method no other calculations are being made
  single_HMunit petHRUOudin;
  petHRUOudin.set_paramsToSim(parsToLoad);
  petHRUOudin.read_InputFromFile("./data/tests/pet_test/in_test/PetTempPrectest.txt");
  petHRUOudin.set_PetVars(50.1,pet_Type::OUDIN);
  petHRUOudin.calc_Pet();
  petHRUOudin.print_OutputToFile("./data/tests/pet_test/out_test/OudinPetTest.txt");

  single_HMunit petHRUHamon;
  petHRUHamon.set_paramsToSim(parsToLoad);
  petHRUHamon.read_InputFromFile("./data/tests/pet_test/in_test/PetTempPrectest.txt");
  petHRUHamon.set_PetVars(50.1,pet_Type::HAMON);
  petHRUHamon.calc_Pet();
  petHRUHamon.print_OutputToFile("./data/tests/pet_test/out_test/HamonPetTest.txt");


  single_HMunit petHRUHamon1;
  petHRUHamon1.set_paramsToSim(parsToLoad);
  petHRUHamon1.read_InputFromFile("./data/tests/inALL/BP_1960_01_01.txt");
  petHRUHamon1.set_PetVars(50.1,pet_Type::HAMON);
  petHRUHamon1.calc_Pet();
  petHRUHamon1.run_HB();
  petHRUHamon1.print_OutputToFile("./data/tests/outALL/outALLdta_BPpartSHRU.txt");



 std::vector<single_HMunit> disHRU;
 single_HMunit sHRU_to_VEC;

 for(int i=0;i<10;i++)   disHRU.push_back(sHRU_to_VEC);

 std::cout <<"The size of vector of HRUs in dHRU is " << disHRU.size() << std::endl;

 #pragma omp parallel for
 for(int i=0; i<10; i++) {
 disHRU[i].set_paramsToSim(parsToLoad);
 disHRU[i].read_InputFromFile("./data/tests/pet_test/in_test/PetTempPrectest.txt");
 disHRU[i].set_PetVars(50.1,pet_Type::OUDIN);
 disHRU[i].calc_Pet();
 disHRU[i].run_HB();
 std::cout << "Calculating the HRU " << i << std::endl;
}

  std::vector<std::pair<numberSel,par_HRUtype>> myParsToLoad;

  myParsToLoad.push_back(std::make_pair(2., par_HRUtype::B_SOIL));
  myParsToLoad.push_back(std::make_pair(1.0, par_HRUtype::C_MAX));
  myParsToLoad.push_back(std::make_pair(0.30, par_HRUtype::B_EVAP));
  myParsToLoad.push_back(std::make_pair(0.1 , par_HRUtype::KS));
  myParsToLoad.push_back(std::make_pair(0.1, par_HRUtype::KF));
  myParsToLoad.push_back(std::make_pair(0.4, par_HRUtype::ADIV));
  myParsToLoad.push_back(std::make_pair(0.1, par_HRUtype::CDIV));
  myParsToLoad.push_back(std::make_pair(0.1, par_HRUtype::SDIV));
  myParsToLoad.push_back(std::make_pair(1.00, par_HRUtype::CAN_ST));
  myParsToLoad.push_back(std::make_pair(1.00, par_HRUtype::STEM_ST));
  myParsToLoad.push_back(std::make_pair(0.50, par_HRUtype::CSDIV));
  myParsToLoad.push_back(std::make_pair(0.95, par_HRUtype::DDFA));
  myParsToLoad.push_back(std::make_pair(10.00, par_HRUtype::RETCAP));


  // single_HMunit sHRU_to_VEC;
  sHRU_to_VEC.setIdHru("sezam");

  numberDta dimHRU = 100;

  hdata vctAreas(10.0,dimHRU);

// //// static dHR U instance
// //  dHRU dhru;
// //  dhru.initHrusVec(dimHRU, sHRU_to_VEC);
// //  dhru.setAreasToHrus(vctAreas);
// //  std::string namInpFilet("./data/tests/inALL/BP_1960_01_01.txt");
// ////  std::string namInpFilet("./data/tests/inALL/BP_1960_01_01part.txt");
// //  dhru.setInputsToHrus(namInpFilet.c_str(),true,0);
// //  dhru.setParamsToHrus(myParsToLoad,true,0);
// //  dhru.setParamsToHrus(parsToLoad,true,0);
// //  dhru.calcPetToHrus(50.1, pet_Type::HAMON,true,0);
// //  dhru.calcHbToHrus();
// //  dhru.gatherTsFromHrus();
// ////  dhru.printAllDta("./data/tests/outALL/outALLdta_BPpart.txt");
// //  dhru.printAllDta("./data/tests/outALL/outALLdta_BP.txt");


// //// implicit form
// //// 1) creates dHRU instance on the heap (allocates memory and call constructor with no arguments)
// //// 2) creates dhruPTR variable on the stack initialized with pointer to dHRU's instance
// //  dHRU *dhruPTR = new dHRU();
// //  dhruPTR->initHrusVec(dimHRU, sHRU_to_VEC);
// //  dhruPTR->setAreasToHrus(vctAreas);
// //  std::string namInpFilet2("./data/tests/inALL/BP_1960_01_01.txt");
// ////  std::string namInpFilet("./data/tests/inALL/BP_1960_01_01part.txt");
// //  dhruPTR->setInputsToHrus(namInpFilet2.c_str(),true,0);
// //  dhruPTR->setParamsToHrus(myParsToLoad, true,0);
// //  dhruPTR->setParamsToHrus(parsToLoad);
// //  dhruPTR->calcPetToHrus(50.1, pet_Type::HAMON,true,0);
// //  dhruPTR->calcHbToHrus();
// //  dhruPTR->gatherTsFromHrus();
// ////  dhru.printAllDta("./data/tests/outALL/outALLdta_BPpart.txt");
// //  dhruPTR->printAllDta("./data/tests/outALL/outALLdta_BP.txt");

// //// explicit form
// //// 1) creates dHRU instance on the heap (allocates memory and call constructor with no arguments)
// //// 2) creates dhruPTR2 variable on the stack initialized with pointer to dHRU's instance
// //  dHRU* dhruPTR2(new dHRU());
// //  dhruPTR2->initHrusVec(dimHRU, sHRU_to_VEC);
// //  dhruPTR2->setAreasToHrus(vctAreas);
// //  std::string namInpFilet1("./data/tests/inALL/BP_1960_01_01.txt");
// ////  std::string namInpFilet("./data/tests/inALL/BP_1960_01_01part.txt");
// //  dhruPTR2->setInputsToHrus(namInpFilet1.c_str(),true,0);
// //  dhruPTR2->setParamsToHrus(myParsToLoad,true,0);
// //  dhruPTR2->setParamsToHrus(parsToLoad,true,0);
// //  dhruPTR2->calcPetToHrus(50.1, pet_Type::HAMON,true,0);
// //  dhruPTR2->calcHbToHrus();
// //  dhruPTR2->gatherTsFromHrus();
// ////  dhru.printAllDta("./data/tests/outALL/outALLdta_BPpart.txt");
// //  dhruPTR2->printAllDta("./data/tests/outALL/outALLdta_BP.txt");


// 1) creates uninitialized dhruPTR3 variable on the stack
// 2) creates dHRU instance on the heap (allocates memory and call constructor with no arguments)
// 3) assigns dhruPTR3 with pointer to dHRU's instance
  dHRUM *dhruPTR3; 
  numberDta dimHRUs = 10;
  hdata vctAreaS(10.0,dimHRUs);

  std::vector<gs_STORtype> gs_STORtype_vec;
  for(unsigned int i=0; i<dimHRUs; i++) {
    gs_STORtype_vec.push_back(gs_STORtype::EXP_RES);
  }
  dhruPTR3 = new(dHRUM);
  dhruPTR3->initHrusVec(dimHRUs, sHRU_to_VEC);
 // dhruPTR3->init_STORtypes(gs_STORtype_vec);
  dhruPTR3->setAreasToHrus(vctAreaS);
  std::string namInpFilet3("./data/tests/inALL/BP_1960_01_01.txt");
//  std::string namInpFilet("./data/tests/inALL/BP_1960_01_01part.txt");
  dhruPTR3->setInputsToAllHrus(namInpFilet3.c_str());
  dhruPTR3->setParamsToAlldHrus(myParsToLoad);
  dhruPTR3->setParamsToAlldHrus(parsToLoad);
  dhruPTR3->calcPetToAllHrus(50.1, pet_Type::HAMON);
  dhruPTR3->calcHbToAllHrus();
  dhruPTR3->gatherTsFromHrus();
//  dhru.printAllDta("./data/tests/outALL/outALLdta_BPpart.txt");
  dhruPTR3->printAllDta("./data/tests/outALL/outALLdta_BP.txt");

  return 0;
}
