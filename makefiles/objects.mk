#########################
### MEKD core objects ###
#########################

objects0=\
$(INCDIR1)/MEKD.o \
$(INCDIR1)/MEKD_v2.o \
$(INCDIR1)/Load_ME_runners.o \
$(INCDIR1)/Load_ME_runners_Other_4l.o \
$(INCDIR1)/Load_ME_runners_Spin0_4l.o \
$(INCDIR1)/Load_ME_runners_Spin1_4l.o \
$(INCDIR1)/Load_ME_runners_Spin2_4l.o \
$(INCDIR1)/Load_ME_runners_Spin0_ttbb.o \
$(INCDIR1)/Load_ME_runners_Other_ttbb.o \
$(INCDIR1)/MEKD_sorter.o $(INCDIR1)/MEKD_RunMEs.o \
$(INCDIR1)/MEKD_debug.o $(INCDIR1)/Defaults.o \
$(INCDIR1)/MEKD_stuff.o \
$(INCDIR1)/Parameters_configurators.o \
$(INCDIR1)/ME_runners/Other_4l_basic.o \
$(INCDIR1)/ME_runners/Other_4l_eval.o \
$(INCDIR1)/ME_runners/Other_4l_init.o \
$(INCDIR1)/ME_runners/Other_4l_prelim.o \
$(INCDIR1)/ME_runners/Spin0_4l_basic.o \
$(INCDIR1)/ME_runners/Spin0_4l_eval.o \
$(INCDIR1)/ME_runners/Spin0_4l_init.o \
$(INCDIR1)/ME_runners/Spin1_4l_prelim.o \
$(INCDIR1)/ME_runners/Spin1_4l_basic.o \
$(INCDIR1)/ME_runners/Spin1_4l_eval.o \
$(INCDIR1)/ME_runners/Spin1_4l_init.o \
$(INCDIR1)/ME_runners/Spin2_4l_prelim.o \
$(INCDIR1)/ME_runners/Other_ttbb_basic.o \
$(INCDIR1)/ME_runners/Other_ttbb_eval.o \
$(INCDIR1)/ME_runners/Other_ttbb_init.o \
$(INCDIR1)/ME_runners/Spin0_ttbb_basic.o \
$(INCDIR1)/ME_runners/Spin0_ttbb_eval.o \
$(INCDIR1)/ME_runners/Spin0_ttbb_init.o



#####################
### Misc. objects ###
#####################

objects1=\
$(INCDIR1)/Extra_code/MEKD_CalcHEP_PDF.o \
$(INCDIR1)/Extra_code/MEKD_CalcHEP_Extra_functions.o \
$(INCDIR1)/Extra_code/MEKD_Boosts.o \
$(INCDIR1)/higgs_properties/hggeffective.o \
$(PDF_DIR)/pdt.o



################################
### Commons for fused models ###
################################

objects2=\
$(INCDIR2_0)/Parameters_MEKD.o $(INCDIR2_0)/read_slha_MEKD.o



####################################
###                              ###
### Models: HEF_UFO, HZZ_Unitary ###
###                              ###
####################################

objects3_C=\
$(INCDIR2_2_src)/HelAmps_HEF_UFO_bkg.o \
$(INCDIR2_2_src)/HelAmps_HZZ_Unitary_bkgpA.o



############################
### SM Z-based processes ###
############################

objects3_Z4l=\
$(INCDIR2_2)/Z4l/qq_Z4l_BKG_DN_OF.o $(INCDIR2_2)/Z4l/qq_Z4l_BKG_DN_OFpA.o \
$(INCDIR2_2)/Z4l/qq_Z4l_BKG_DN_SF.o $(INCDIR2_2)/Z4l/qq_Z4l_BKG_DN_SFpA.o \
$(INCDIR2_2)/Z4l/qq_Z4l_BKG_UP_OF.o $(INCDIR2_2)/Z4l/qq_Z4l_BKG_UP_OFpA.o \
$(INCDIR2_2)/Z4l/qq_Z4l_BKG_UP_SF.o $(INCDIR2_2)/Z4l/qq_Z4l_BKG_UP_SFpA.o \
$(INCDIR2_2)/Z4l/qq_Z4l_SIG_DN_OF.o $(INCDIR2_2)/Z4l/qq_Z4l_SIG_DN_OFpA.o \
$(INCDIR2_2)/Z4l/qq_Z4l_SIG_DN_SF.o $(INCDIR2_2)/Z4l/qq_Z4l_SIG_DN_SFpA.o \
$(INCDIR2_2)/Z4l/qq_Z4l_SIG_UP_OF.o $(INCDIR2_2)/Z4l/qq_Z4l_SIG_UP_OFpA.o \
$(INCDIR2_2)/Z4l/qq_Z4l_SIG_UP_SF.o $(INCDIR2_2)/Z4l/qq_Z4l_SIG_UP_SFpA.o

objects3_ZZ=\
$(INCDIR2_2)/ZZ/qq_ZZ_DN_OF.o $(INCDIR2_2)/ZZ/qq_ZZ_UP_OF.o \
$(INCDIR2_2)/ZZ/qq_ZZ_DN_SF.o $(INCDIR2_2)/ZZ/qq_ZZ_UP_SF.o \
$(INCDIR2_2)/ZZ/qq_ZZ_DN_OFpA.o $(INCDIR2_2)/ZZ/qq_ZZ_UP_OFpA.o \
$(INCDIR2_2)/ZZ/qq_ZZ_DN_SFpA.o $(INCDIR2_2)/ZZ/qq_ZZ_UP_SFpA.o



########################
###                  ###
### Model: HEF_MEKDn ###
###                  ###
########################

objects4_C=\
$(INCDIR2_1_src)/HelAmps_HEF_MEKD2_1.o $(INCDIR2_1_src)/HelAmps_HEF_MEKD.o



############################
### SM Z-based processes ###
############################

objects4_DY=\
$(INCDIR2_1)/DY/qq_DY_DN_2l.o $(INCDIR2_1)/DY/qq_DY_UP_2l.o \
$(INCDIR2_1)/DY/qq_DY_DN_2lpA.o $(INCDIR2_1)/DY/qq_DY_UP_2lpA.o \
$(INCDIR2_1)/DY/DY_2l.o $(INCDIR2_1)/DY/DY_2lpA.o



##################################
### Spin-0 resonance processes ###
##################################

objects4_spin0=\
$(INCDIR2_1)/Spin0/gg_Spin0_OF.o $(INCDIR2_1)/Spin0/gg_Spin0_SF.o \
$(INCDIR2_1)/Spin0/gg_Spin0_OFpA.o $(INCDIR2_1)/Spin0/gg_Spin0_SFpA.o \
$(INCDIR2_1)/Spin0/Spin0_OF.o $(INCDIR2_1)/Spin0/Spin0_SF.o \
$(INCDIR2_1)/Spin0/Spin0_OFpA.o $(INCDIR2_1)/Spin0/Spin0_SFpA.o
# $(INCDIR2_1)/Spin0/qq_Spin0_DN_OF.o $(INCDIR2_1)/Spin0/qq_Spin0_UP_OF.o \
# $(INCDIR2_1)/Spin0/qq_Spin0_DN_SF.o $(INCDIR2_1)/Spin0/qq_Spin0_UP_SF.o \
# $(INCDIR2_1)/Spin0/qq_Spin0_DN_OFpA.o $(INCDIR2_1)/Spin0/qq_Spin0_UP_OFpA.o \
# $(INCDIR2_1)/Spin0/qq_Spin0_DN_SFpA.o $(INCDIR2_1)/Spin0/qq_Spin0_UP_SFpA.o

objects4_spin0_2=\
$(INCDIR2_1)/Spin0/gg_Spin0_2l.o $(INCDIR2_1)/Spin0/gg_Spin0_2lpA.o \
$(INCDIR2_1)/Spin0/Spin0_2l.o $(INCDIR2_1)/Spin0/Spin0_2lpA.o
# $(INCDIR2_1)/Spin0/qq_Spin0_DN_2l.o $(INCDIR2_1)/Spin0/qq_Spin0_DN_2lpA.o \
# $(INCDIR2_1)/Spin0/qq_Spin0_UP_2l.o $(INCDIR2_1)/Spin0/qq_Spin0_UP_2lpA.o

objects4_spin0_3=\
$(INCDIR2_1)/Spin0/gg_Spin0_2f_OF.o $(INCDIR2_1)/Spin0/gg_Spin0_2f_SF.o \
$(INCDIR2_1)/Spin0/gg_Spin0_2f_OFpA.o $(INCDIR2_1)/Spin0/gg_Spin0_2f_SFpA.o \
$(INCDIR2_1)/Spin0/Spin0_2f_OF.o $(INCDIR2_1)/Spin0/Spin0_2f_SF.o \
$(INCDIR2_1)/Spin0/Spin0_2f_OFpA.o $(INCDIR2_1)/Spin0/Spin0_2f_SFpA.o



##################################
### Spin-1 resonance processes ###
##################################

objects4_spin1=\
$(INCDIR2_1)/Spin1/qq_Spin1_DN_OF.o $(INCDIR2_1)/Spin1/qq_Spin1_UP_OF.o \
$(INCDIR2_1)/Spin1/qq_Spin1_DN_SF.o $(INCDIR2_1)/Spin1/qq_Spin1_UP_SF.o \
$(INCDIR2_1)/Spin1/qq_Spin1_DN_OFpA.o $(INCDIR2_1)/Spin1/qq_Spin1_UP_OFpA.o \
$(INCDIR2_1)/Spin1/qq_Spin1_DN_SFpA.o $(INCDIR2_1)/Spin1/qq_Spin1_UP_SFpA.o \
$(INCDIR2_1)/Spin1/Spin1_OF.o $(INCDIR2_1)/Spin1/Spin1_SF.o \
$(INCDIR2_1)/Spin1/Spin1_OFpA.o $(INCDIR2_1)/Spin1/Spin1_SFpA.o

objects4_spin1_2=\
$(INCDIR2_1)/Spin1/qq_Spin1_DN_2l.o $(INCDIR2_1)/Spin1/qq_Spin1_UP_2l.o \
$(INCDIR2_1)/Spin1/qq_Spin1_DN_2lpA.o $(INCDIR2_1)/Spin1/qq_Spin1_UP_2lpA.o \
$(INCDIR2_1)/Spin1/Spin1_2l.o $(INCDIR2_1)/Spin1/Spin1_2lpA.o

objects4_spin1_3=\
$(INCDIR2_1)/Spin1/qq_Spin1_2f_DN_OF.o $(INCDIR2_1)/Spin1/qq_Spin1_2f_UP_OF.o \
$(INCDIR2_1)/Spin1/qq_Spin1_2f_DN_SF.o $(INCDIR2_1)/Spin1/qq_Spin1_2f_UP_SF.o \
$(INCDIR2_1)/Spin1/qq_Spin1_2f_DN_OFpA.o $(INCDIR2_1)/Spin1/qq_Spin1_2f_UP_OFpA.o \
$(INCDIR2_1)/Spin1/qq_Spin1_2f_DN_SFpA.o $(INCDIR2_1)/Spin1/qq_Spin1_2f_UP_SFpA.o \
$(INCDIR2_1)/Spin1/Spin1_2f_OF.o $(INCDIR2_1)/Spin1/Spin1_2f_SF.o \
$(INCDIR2_1)/Spin1/Spin1_2f_OFpA.o $(INCDIR2_1)/Spin1/Spin1_2f_SFpA.o



##################################
### Spin-2 resonance processes ###
##################################

objects4_spin2=\
$(INCDIR2_1)/Spin2/gg_Spin2_OF.o $(INCDIR2_1)/Spin2/gg_Spin2_SF.o \
$(INCDIR2_1)/Spin2/gg_Spin2_OFpA.o $(INCDIR2_1)/Spin2/gg_Spin2_SFpA.o \
$(INCDIR2_1)/Spin2/qq_Spin2_DN_OF.o $(INCDIR2_1)/Spin2/qq_Spin2_UP_OF.o \
$(INCDIR2_1)/Spin2/qq_Spin2_DN_SF.o $(INCDIR2_1)/Spin2/qq_Spin2_UP_SF.o \
$(INCDIR2_1)/Spin2/qq_Spin2_DN_OFpA.o $(INCDIR2_1)/Spin2/qq_Spin2_UP_OFpA.o \
$(INCDIR2_1)/Spin2/qq_Spin2_DN_SFpA.o $(INCDIR2_1)/Spin2/qq_Spin2_UP_SFpA.o \
$(INCDIR2_1)/Spin2/Spin2_OF.o $(INCDIR2_1)/Spin2/Spin2_SF.o \
$(INCDIR2_1)/Spin2/Spin2_OFpA.o $(INCDIR2_1)/Spin2/Spin2_SFpA.o

objects4_spin2_2=\
$(INCDIR2_1)/Spin2/gg_Spin2_2l.o $(INCDIR2_1)/Spin2/qq_Spin2_DN_2l.o \
$(INCDIR2_1)/Spin2/qq_Spin2_UP_2l.o $(INCDIR2_1)/Spin2/gg_Spin2_2lpA.o \
$(INCDIR2_1)/Spin2/qq_Spin2_DN_2lpA.o $(INCDIR2_1)/Spin2/qq_Spin2_UP_2lpA.o \
$(INCDIR2_1)/Spin2/Spin2_2l.o $(INCDIR2_1)/Spin2/Spin2_2lpA.o 

objects4_spin2_3=\
$(INCDIR2_1)/Spin2/gg_Spin2_2f_OF.o $(INCDIR2_1)/Spin2/gg_Spin2_2f_SF.o \
$(INCDIR2_1)/Spin2/gg_Spin2_2f_OFpA.o $(INCDIR2_1)/Spin2/gg_Spin2_2f_SFpA.o \
$(INCDIR2_1)/Spin2/qq_Spin2_2f_DN_OF.o $(INCDIR2_1)/Spin2/qq_Spin2_2f_UP_OF.o \
$(INCDIR2_1)/Spin2/qq_Spin2_2f_DN_SF.o $(INCDIR2_1)/Spin2/qq_Spin2_2f_UP_SF.o \
$(INCDIR2_1)/Spin2/qq_Spin2_2f_DN_OFpA.o $(INCDIR2_1)/Spin2/qq_Spin2_2f_UP_OFpA.o \
$(INCDIR2_1)/Spin2/qq_Spin2_2f_DN_SFpA.o $(INCDIR2_1)/Spin2/qq_Spin2_2f_UP_SFpA.o \
$(INCDIR2_1)/Spin2/Spin2_2f_OF.o $(INCDIR2_1)/Spin2/Spin2_2f_SF.o \
$(INCDIR2_1)/Spin2/Spin2_2f_OFpA.o $(INCDIR2_1)/Spin2/Spin2_2f_SFpA.o



######################
###                ###
### Model: sm-full ###
###                ###
######################

objects5_C=\
$(INCDIR2_4_src)/HelAmps_sm_full.o \
$(INCDIR2_4_src)/Parameters_sm_full.o



###############################
### ttH (sm-full) processes ###
###############################

objects5_ttH_smfull=\
$(INCDIR2_4)/ttbb_all/ddx_ttxbbx.o \
$(INCDIR2_4)/ttbb_all/uux_ttxbbx.o \
$(INCDIR2_4)/ttbb_all/ssx_ttxbbx.o \
$(INCDIR2_4)/ttbb_all/ccx_ttxbbx.o \
$(INCDIR2_4)/ttbb_all/bbx_ttxbbx.o \
$(INCDIR2_4)/ttbb_all/gg_ttxbbx.o



################################
###                          ###
### Model: heft_updated-full ###
###                          ###
################################

objects6_C=\
$(INCDIR2_3)/src/HelAmps_heft_updated_full.o \
$(INCDIR2_3)/src/Parameters_heft_updated_full.o



#########################################
### ttH (heft_updated-full) processes ###
#########################################

objects6_ttH_bkg=\
$(INCDIR2_3)/ttbb_all/ddx_ttxbbx.o \
$(INCDIR2_3)/ttbb_all/uux_ttxbbx.o \
$(INCDIR2_3)/ttbb_all/ssx_ttxbbx.o \
$(INCDIR2_3)/ttbb_all/ccx_ttxbbx.o \
$(INCDIR2_3)/ttbb_all/bbx_ttxbbx.o \
$(INCDIR2_3)/ttbb_all/gg_ttxbbx.o



#########################################
### ttH (heft_updated-full) processes ###
#########################################

objects6_ttH=\
$(INCDIR2_3)/h_ttbb/ddx_h_ttxbbx.o \
$(INCDIR2_3)/h_ttbb/uux_h_ttxbbx.o \
$(INCDIR2_3)/h_ttbb/ssx_h_ttxbbx.o \
$(INCDIR2_3)/h_ttbb/ccx_h_ttxbbx.o \
$(INCDIR2_3)/h_ttbb/bbx_h_ttxbbx.o \
$(INCDIR2_3)/h_ttbb/gg_h_ttxbbx.o



###########################################
### ttbar (heft_updated-full) processes ###
###########################################

objects6_bkg=\
$(INCDIR2_3)/noh_ttbb/ddx_noh_ttxbbx.o \
$(INCDIR2_3)/noh_ttbb/uux_noh_ttxbbx.o \
$(INCDIR2_3)/noh_ttbb/ssx_noh_ttxbbx.o \
$(INCDIR2_3)/noh_ttbb/ccx_noh_ttxbbx.o \
$(INCDIR2_3)/noh_ttbb/bbx_noh_ttxbbx.o \
$(INCDIR2_3)/noh_ttbb/gg_noh_ttxbbx.o



##########################
###                    ###
### Model: HiggsPO_UFO ###
###                    ###
##########################

objects7_C=\
$(INCDIR2_5)/src/HelAmps_HiggsPO_UFO.o \
$(INCDIR2_5)/src/Parameters_HiggsPO_UFO.o



#################################################
### Spin-0-resonance (HiggsPO_UFO)  processes ###
#################################################

objects7_spin0=\
$(INCDIR2_5)/Spin0_4l/gg_Spin0_OF.o \
$(INCDIR2_5)/Spin0_4l/gg_Spin0_SF.o \
$(INCDIR2_5)/Spin0_4l/Spin0_OF.o \
$(INCDIR2_5)/Spin0_4l/Spin0_SF.o



##############################
###                        ###
### Model: Leptophilic_UFO ###
###                        ###
##############################

objects8_C=\
$(INCDIR2_6)/src/HelAmps_Leptophilic_UFO.o \
$(INCDIR2_6)/src/Parameters_Leptophilic_UFO.o



#########################################
### z_zp (Leptophilic_UFO)  processes ###
#########################################

objects8_z_zp=\
$(INCDIR2_6)/z_zp/qq_z_zp_DN_OF.o \
$(INCDIR2_6)/z_zp/qq_z_zp_DN_SF.o \
$(INCDIR2_6)/z_zp/qq_z_zp_UP_OF.o \
$(INCDIR2_6)/z_zp/qq_z_zp_UP_SF.o \
$(INCDIR2_6)/z_zp/qq_z_zp_DN_OFpA.o \
$(INCDIR2_6)/z_zp/qq_z_zp_DN_SFpA.o \
$(INCDIR2_6)/z_zp/qq_z_zp_UP_OFpA.o \
$(INCDIR2_6)/z_zp/qq_z_zp_UP_SFpA.o



########################
### Combined objects ###
########################

objects3=$(objects3_C) \
$(objects3_ZZ) $(objects3_Z4l)

objects4=$(objects4_C) \
$(objects4_DY) \
$(objects4_spin0) $(objects4_spin0_2) $(objects4_spin0_3) \
$(objects4_spin1) $(objects4_spin1_2) $(objects4_spin1_3) \
$(objects4_spin2) $(objects4_spin2_2) $(objects4_spin2_3)

objects5=$(objects5_C) \
$(objects5_ttH_smfull)

objects6=$(objects6_C) \
$(objects6_ttH_bkg) $(objects6_ttH) $(objects6_bkg)

objects7=$(objects7_C) \
$(objects7_spin0)

objects8=$(objects8_C) \
$(objects8_z_zp)

objects=$(objects0) $(objects1) $(objects2) $(objects3) $(objects4) \
$(objects5) $(objects6) $(objects7) $(objects8)
