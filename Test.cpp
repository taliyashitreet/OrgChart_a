#include "doctest.h"
#include <iostream>
#include "OrgChart.hpp"
#include <string>
#include <vector>
using namespace std;
using namespace ariel;

TEST_CASE("test1"){
OrgChart organization;
CHECK_NOTHROW(organization.add_root("CEO"));
CHECK_NOTHROW(organization.add_sub("CEO", "CTO"));        // Now the CTO is subordinate to the CEO
CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));         // Now the CFO is subordinate to the CEO
CHECK_NOTHROW(organization.add_sub("CEO", "CFO"));         // Now the COO is subordinate to the CEO
CHECK_NOTHROW(organization.add_sub("CTO", "VP_SW")); // Now the VP Software is subordinate to the CTO
CHECK_NOTHROW(organization.add_sub("COO", "VP_BI"));      // Now the VP_BI is subordinate to the COO
vector<string> level = {"CEO","CTO","CFO","COO","VP_SW","VP_BI"}; // level order
unsigned int index = 0;
for (auto element : organization){ //this loop go like level order
    CHECK(level.at(index)==element);
    index+=1;
}
for (auto it = organization.begin_reverse_order(); it != organization.reverse_order(); ++it)
  {
      CHECK(level.at(index)==*it); //revers loop of level order
      index-=1;
  }

vector<string> pre = {"CEO","CTO","VP_SW","CFO","COO","VP_BI"};
for (auto it=organization.begin_preorder(); it!=organization.end_preorder(); ++it) {
 CHECK(pre.at(index)==*it);
 index+=1;
}
CHECK_THROWS(organization.add_sub("taliya", "lalala")); // the organosation doesnt have this names
CHECK_THROWS(organization.add_sub("lalala", "taliya"));
CHECK_THROWS(organization.add_sub("roni", "rotem"));


}

TEST_CASE("test2"){
    OrgChart organization2;
CHECK_NOTHROW(organization2.add_root("DAVID"));
CHECK_NOTHROW(organization2.add_sub("DAVID", "RONI"));        // Now the CTO is subordinate to the CEO
CHECK_NOTHROW(organization2.add_sub("RONI", "ELICK"));         // Now the CFO is subordinate to the CEO
CHECK_NOTHROW(organization2.add_sub("RONI", "TALIYA"));         // Now the COO is subordinate to the CEO
CHECK_NOTHROW(organization2.add_sub("RONI", "ROEI")); // Now the VP Software is subordinate to the CTO     // Now the VP_BI is subordinate to the COO
vector<string> check = {"DAVID","RONI","ELICK","TALIYA","ROEI"}; // level order
unsigned int index = 0;
for (auto element : organization2){ //this loop go like level order
    CHECK(check.at(index)==element);
    index+=1;
}
for (auto it = organization2.begin_reverse_order(); it != organization2.reverse_order(); ++it)
  {
      CHECK(check.at(index)==*it); //revers loop of level order
      index-=1;
  }

for (auto it=organization2.begin_preorder(); it!=organization2.end_preorder(); ++it) {
 CHECK(check.at(index)==*it);
 index+=1;
}
CHECK_THROWS(organization2.add_sub("Ela", "lalala"));
CHECK_THROWS(organization2.add_sub("lalala", "Ela"));
CHECK_THROWS(organization2.add_sub("Rotem", "Amit"));
}