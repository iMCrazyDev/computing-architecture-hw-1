file(REMOVE_RECURSE
  "../bin/test.exe"
  "../bin/test.exe.manifest"
  "../bin/test.pdb"
  "CMakeFiles/test.dir/test.cpp.obj"
  "libtest.dll.a"
)

# Per-language clean rules from dependency scanning.
foreach(lang CXX)
  include(CMakeFiles/test.dir/cmake_clean_${lang}.cmake OPTIONAL)
endforeach()
