##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Picareta
ConfigurationName      :=Debug
WorkspacePath          := "C:\NovaPasta\ProgII"
ProjectPath            := "C:\Users\LAB4-PC10\Documents\GitHub\Picareta\Picareta"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=LAB4-PC10
Date                   :=06/10/2014
CodeLitePath           :="C:\Program Files\CodeLite"
LinkerName             :=g++
SharedObjectLinkerName :=g++ -shared -fPIC
ObjectSuffix           :=.o
DependSuffix           :=.o.d
PreprocessSuffix       :=.o.i
DebugSwitch            :=-gstab
IncludeSwitch          :=-I
LibrarySwitch          :=-l
OutputSwitch           :=-o 
LibraryPathSwitch      :=-L
PreprocessorSwitch     :=-D
SourceSwitch           :=-c 
OutputFile             :=$(IntermediateDirectory)/$(ProjectName)
Preprocessors          :=
ObjectSwitch           :=-o 
ArchiveOutputSwitch    := 
PreprocessOnlySwitch   :=-E 
ObjectsFileList        :="Picareta.txt"
PCHCompileFlags        :=
MakeDirCommand         :=makedir
RcCmpOptions           := 
RcCompilerName         :=windres
LinkOptions            :=  -pg 
IncludePath            :=  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                := $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -pg -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -pg -O0 -Wall $(Preprocessors)


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main$(ObjectSuffix) $(IntermediateDirectory)/Picareta$(ObjectSuffix) $(IntermediateDirectory)/Ferramenta$(ObjectSuffix) $(IntermediateDirectory)/Inventario$(ObjectSuffix) $(IntermediateDirectory)/Bloco$(ObjectSuffix) 



Objects=$(Objects0) 

##
## Main Build Targets 
##
.PHONY: all clean PreBuild PrePreBuild PostBuild
all: $(OutputFile)

$(OutputFile): $(IntermediateDirectory)/.d $(Objects) 
	@$(MakeDirCommand) $(@D)
	@echo "" > $(IntermediateDirectory)/.d
	@echo $(Objects0)  > $(ObjectsFileList)
	$(LinkerName) $(OutputSwitch)$(OutputFile) @$(ObjectsFileList) $(LibPath) $(Libs) $(LinkOptions)

$(IntermediateDirectory)/.d:
	@$(MakeDirCommand) "./Debug"

PreBuild:


##
## Objects
##
$(IntermediateDirectory)/main$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC10/Documents/GitHub/Picareta/Picareta/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main$(ObjectSuffix) -MF$(IntermediateDirectory)/main$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Picareta$(ObjectSuffix): Picareta.cpp $(IntermediateDirectory)/Picareta$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC10/Documents/GitHub/Picareta/Picareta/Picareta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Picareta$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Picareta$(DependSuffix): Picareta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Picareta$(ObjectSuffix) -MF$(IntermediateDirectory)/Picareta$(DependSuffix) -MM "Picareta.cpp"

$(IntermediateDirectory)/Picareta$(PreprocessSuffix): Picareta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Picareta$(PreprocessSuffix) "Picareta.cpp"

$(IntermediateDirectory)/Ferramenta$(ObjectSuffix): Ferramenta.cpp $(IntermediateDirectory)/Ferramenta$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC10/Documents/GitHub/Picareta/Picareta/Ferramenta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Ferramenta$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Ferramenta$(DependSuffix): Ferramenta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Ferramenta$(ObjectSuffix) -MF$(IntermediateDirectory)/Ferramenta$(DependSuffix) -MM "Ferramenta.cpp"

$(IntermediateDirectory)/Ferramenta$(PreprocessSuffix): Ferramenta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Ferramenta$(PreprocessSuffix) "Ferramenta.cpp"

$(IntermediateDirectory)/Inventario$(ObjectSuffix): Inventario.cpp $(IntermediateDirectory)/Inventario$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC10/Documents/GitHub/Picareta/Picareta/Inventario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Inventario$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Inventario$(DependSuffix): Inventario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Inventario$(ObjectSuffix) -MF$(IntermediateDirectory)/Inventario$(DependSuffix) -MM "Inventario.cpp"

$(IntermediateDirectory)/Inventario$(PreprocessSuffix): Inventario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Inventario$(PreprocessSuffix) "Inventario.cpp"

$(IntermediateDirectory)/Bloco$(ObjectSuffix): Bloco.cpp $(IntermediateDirectory)/Bloco$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/LAB4-PC10/Documents/GitHub/Picareta/Picareta/Bloco.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bloco$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bloco$(DependSuffix): Bloco.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bloco$(ObjectSuffix) -MF$(IntermediateDirectory)/Bloco$(DependSuffix) -MM "Bloco.cpp"

$(IntermediateDirectory)/Bloco$(PreprocessSuffix): Bloco.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bloco$(PreprocessSuffix) "Bloco.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) $(IntermediateDirectory)/main$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/main$(DependSuffix)
	$(RM) $(IntermediateDirectory)/main$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Picareta$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Picareta$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Picareta$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Ferramenta$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Ferramenta$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Ferramenta$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Inventario$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Inventario$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Inventario$(PreprocessSuffix)
	$(RM) $(IntermediateDirectory)/Bloco$(ObjectSuffix)
	$(RM) $(IntermediateDirectory)/Bloco$(DependSuffix)
	$(RM) $(IntermediateDirectory)/Bloco$(PreprocessSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../../../../../../NovaPasta/ProgII/.build-debug/Picareta"


