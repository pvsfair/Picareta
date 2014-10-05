##
## Auto Generated makefile by CodeLite IDE
## any manual changes will be erased      
##
## Debug
ProjectName            :=Picareta
ConfigurationName      :=Debug
WorkspacePath          := "C:\Users\Paulo\Documents\GitHub\Picareta"
ProjectPath            := "C:\Users\Paulo\Documents\GitHub\Picareta\Picareta"
IntermediateDirectory  :=./Debug
OutDir                 := $(IntermediateDirectory)
CurrentFileName        :=
CurrentFilePath        :=
CurrentFileFullPath    :=
User                   :=Paulo
Date                   :=10/05/14
CodeLitePath           :="C:\Program Files (x86)\CodeLite"
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
LinkOptions            :=  
IncludePath            := $(IncludeSwitch)"C:/Program Files (x86)/Graphviz2.38/include/graphviz"  $(IncludeSwitch). $(IncludeSwitch). 
IncludePCH             := 
RcIncludePath          := 
Libs                   := 
ArLibs                 :=  
LibPath                :=$(LibraryPathSwitch)"C:/Program Files (x86)/Graphviz2.38/lib/release/lib"  $(LibraryPathSwitch). 

##
## Common variables
## AR, CXX, CC, AS, CXXFLAGS and CFLAGS can be overriden using an environment variables
##
AR       := ar rcus
CXX      := g++
CC       := gcc
CXXFLAGS :=  -g -O0 -Wall $(Preprocessors)
CFLAGS   :=  -g -O0 -Wall $(Preprocessors)
ASFLAGS  := 
AS       := as


##
## User defined environment variables
##
CodeLiteDir:=C:\Program Files (x86)\CodeLite
UNIT_TEST_PP_SRC_DIR:=C:\UnitTest++-1.3
Objects0=$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IntermediateDirectory)/Picareta.cpp$(ObjectSuffix) $(IntermediateDirectory)/Ferramenta.cpp$(ObjectSuffix) $(IntermediateDirectory)/Inventario.cpp$(ObjectSuffix) $(IntermediateDirectory)/Bloco.cpp$(ObjectSuffix) 



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
$(IntermediateDirectory)/main.cpp$(ObjectSuffix): main.cpp $(IntermediateDirectory)/main.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Paulo/Documents/GitHub/Picareta/Picareta/main.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/main.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/main.cpp$(DependSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/main.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/main.cpp$(DependSuffix) -MM "main.cpp"

$(IntermediateDirectory)/main.cpp$(PreprocessSuffix): main.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/main.cpp$(PreprocessSuffix) "main.cpp"

$(IntermediateDirectory)/Picareta.cpp$(ObjectSuffix): Picareta.cpp $(IntermediateDirectory)/Picareta.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Paulo/Documents/GitHub/Picareta/Picareta/Picareta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Picareta.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Picareta.cpp$(DependSuffix): Picareta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Picareta.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Picareta.cpp$(DependSuffix) -MM "Picareta.cpp"

$(IntermediateDirectory)/Picareta.cpp$(PreprocessSuffix): Picareta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Picareta.cpp$(PreprocessSuffix) "Picareta.cpp"

$(IntermediateDirectory)/Ferramenta.cpp$(ObjectSuffix): Ferramenta.cpp $(IntermediateDirectory)/Ferramenta.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Paulo/Documents/GitHub/Picareta/Picareta/Ferramenta.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Ferramenta.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Ferramenta.cpp$(DependSuffix): Ferramenta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Ferramenta.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Ferramenta.cpp$(DependSuffix) -MM "Ferramenta.cpp"

$(IntermediateDirectory)/Ferramenta.cpp$(PreprocessSuffix): Ferramenta.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Ferramenta.cpp$(PreprocessSuffix) "Ferramenta.cpp"

$(IntermediateDirectory)/Inventario.cpp$(ObjectSuffix): Inventario.cpp $(IntermediateDirectory)/Inventario.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Paulo/Documents/GitHub/Picareta/Picareta/Inventario.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Inventario.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Inventario.cpp$(DependSuffix): Inventario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Inventario.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Inventario.cpp$(DependSuffix) -MM "Inventario.cpp"

$(IntermediateDirectory)/Inventario.cpp$(PreprocessSuffix): Inventario.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Inventario.cpp$(PreprocessSuffix) "Inventario.cpp"

$(IntermediateDirectory)/Bloco.cpp$(ObjectSuffix): Bloco.cpp $(IntermediateDirectory)/Bloco.cpp$(DependSuffix)
	$(CXX) $(IncludePCH) $(SourceSwitch) "C:/Users/Paulo/Documents/GitHub/Picareta/Picareta/Bloco.cpp" $(CXXFLAGS) $(ObjectSwitch)$(IntermediateDirectory)/Bloco.cpp$(ObjectSuffix) $(IncludePath)
$(IntermediateDirectory)/Bloco.cpp$(DependSuffix): Bloco.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) -MG -MP -MT$(IntermediateDirectory)/Bloco.cpp$(ObjectSuffix) -MF$(IntermediateDirectory)/Bloco.cpp$(DependSuffix) -MM "Bloco.cpp"

$(IntermediateDirectory)/Bloco.cpp$(PreprocessSuffix): Bloco.cpp
	@$(CXX) $(CXXFLAGS) $(IncludePCH) $(IncludePath) $(PreprocessOnlySwitch) $(OutputSwitch) $(IntermediateDirectory)/Bloco.cpp$(PreprocessSuffix) "Bloco.cpp"


-include $(IntermediateDirectory)/*$(DependSuffix)
##
## Clean
##
clean:
	$(RM) ./Debug/*$(ObjectSuffix)
	$(RM) ./Debug/*$(DependSuffix)
	$(RM) $(OutputFile)
	$(RM) $(OutputFile).exe
	$(RM) "../.build-debug/Picareta"


