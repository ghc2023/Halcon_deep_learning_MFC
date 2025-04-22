#ifndef __DL_EXPORT_H__
#define __DL_EXPORT_H__

#include "Halconcpp.h"
using namespace HalconCpp;


// Procedure declarations 
// Chapter: Deep Learning / Model
// Short Description: Visualize different images, annotations and inference results for a sample. 
extern void dev_display_dl_data(HTuple hv_DLSample, HTuple hv_DLResult, HTuple hv_DLDatasetInfo,
	HTuple hv_KeysForDisplay, HTuple hv_GenParam, HTuple hv_WindowHandleDict);
// Chapter: Develop
// Short Description: Switch dev_update_pc, dev_update_var and dev_update_window to 'off'. 
extern void dev_update_off();
// Chapter: Develop
// Short Description: Switch dev_update_pc, dev_update_var and dev_update_window to 'off'. 
extern void dev_update_off();
// Chapter: File / Misc
// Short Description: Get all image files under the given path 
extern void list_image_files_ht2(HTuple hv_ImageDirectory, HTuple hv_Extensions,
	HTuple hv_Options, HTuple *hv_ImageFiles);
// Chapter: Deep Learning / Model
// Short Description: Read the dictionaries DLSamples from files. 
extern void read_dl_samples_ht2(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// Chapter: Deep Learning / Model
// Short Description: Read the dictionaries DLSamples from files. 
// extern void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// // Chapter: Deep Learning / Model
// // Short Description: Read the dictionaries DLSamples from files. 
// extern void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// // Chapter: Deep Learning / Model
// // Short Description: Read the dictionaries DLSamples from files. 
// extern void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// // Chapter: Deep Learning / Model
// // Short Description: Read the dictionaries DLSamples from files. 
// extern void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// // Chapter: Deep Learning / Model
// // Short Description: Read the dictionaries DLSamples from files. 
// extern void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// // Chapter: Deep Learning / Model
// // Short Description: Read the dictionaries DLSamples from files. 
// extern void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// // Chapter: Deep Learning / Model
// // Short Description: Read the dictionaries DLSamples from files. 
// extern void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// // Chapter: Deep Learning / Model
// // Short Description: Read the dictionaries DLSamples from files. 
// extern void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// // Chapter: Deep Learning / Model
// // Short Description: Read the dictionaries DLSamples from files. 
// extern void read_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple *hv_DLSampleBatch);
// Chapter: Tuple / Element Order
// Short Description: Sort the elements of a tuple randomly. 
extern void tuple_shuffle_ht2(HTuple hv_Tuple, HTuple *hv_Shuffled);
// Chapter: Tuple / Element Order
// Short Description: Sort the elements of a tuple randomly. 
// extern void tuple_shuffle_ht(HTuple hv_Tuple, HTuple *hv_Shuffled);
// // Chapter: Tuple / Element Order
// // Short Description: Sort the elements of a tuple randomly. 
// extern void tuple_shuffle_ht(HTuple hv_Tuple, HTuple *hv_Shuffled);
// // Chapter: Tuple / Element Order
// // Short Description: Sort the elements of a tuple randomly. 
// extern void tuple_shuffle_ht(HTuple hv_Tuple, HTuple *hv_Shuffled);
// // Chapter: Tuple / Element Order
// // Short Description: Sort the elements of a tuple randomly. 
// extern void tuple_shuffle_ht(HTuple hv_Tuple, HTuple *hv_Shuffled);

void add_colormap_to_image_ht(HObject ho_GrayValueImage, HObject ho_Image, HObject *ho_ColoredImage,
	HTuple hv_HeatmapColorScheme);
// Chapter: Deep Learning / Object Detection
// Short Description: This procedure collects data concerning the shape of the ground truth bounding boxes provided in DLDataset. 
void analyze_dl_dataset_detection_ht(HTuple hv_DLDataset, HTuple hv_InstanceType,
	HTuple hv_ImageWidthRaw, HTuple hv_ImageHeightRaw, HTuple hv_ImageWidthTarget,
	HTuple hv_ImageHeightTarget, HTuple hv_DomainHandling, HTuple hv_PreprocessedPath,
	HTuple hv_DatasetSplit, HTuple *hv_Areas, HTuple *hv_AspectRatios, HTuple *hv_Angles);
// Short Description: Create a lookup table and convert a grey scale image. 
void apply_colorscheme_on_gray_value_image_ht(HObject ho_InputImage, HObject *ho_ResultImage,
	HTuple hv_Schema);
// Chapter: Deep Learning / Evaluation
void area_iou_ht(HTuple hv_Sample, HTuple hv_Result, HTuple hv_InstanceType, HTuple hv_ResultSortIndices,
	HTuple *hv_SampleArea, HTuple *hv_ResultArea, HTuple *hv_IoU);
// Chapter: Deep Learning / Model
// Short Description: Distort the given samples to augment the dataset. 
void augment_dl_samples_ht(HTuple hv_DLSampleBatch, HTuple hv_GenParam);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Calculate the class weights for a semantic segmentation dataset. 
void calculate_dl_segmentation_class_weights_ht(HTuple hv_DLDataset, HTuple hv_MaxWeight,
	HTuple hv_IgnoreClassIDs, HTuple *hv_ClassWeights);
// Chapter: Deep Learning / Evaluation
// Short Description: Calculate evaluation measures based on the values of RunningMeasures and the settings in EvalParams. 
void calculate_evaluation_measures_ht(HTuple hv_RunningMeasures, HTuple hv_EvalParams,
	HTuple *hv_EvaluationResult);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Calculate anomaly detection measures based on RunningMeasures. 
void calculate_image_anomaly_measures_ht(HTuple hv_RunningMeasures, HTuple hv_EvalParams,
	HTuple *hv_EvaluationResult);
// Chapter: Deep Learning / Evaluation
// Short Description: Calculate image classification measures based on RunningMeasures. 
void calculate_image_classification_measures_ht(HTuple hv_RunningMeasures, HTuple hv_EvalParams,
	HTuple *hv_EvaluationResult);
// Chapter: Deep Learning / Evaluation
// Short Description: Calculate instance measures based on RunningMeasures. 
void calculate_instance_measures_ht(HTuple hv_RunningMeasures, HTuple hv_EvalParams,
	HTuple *hv_EvaluationResult);
// Chapter: Deep Learning / Evaluation
// Short Description: Calculate pixel measures based on RunningMeasures. 
void calculate_pixel_measures_ht(HTuple hv_RunningMeasures, HTuple hv_EvalParams,
	HTuple *hv_EvaluationResult);
// Chapter: Deep Learning / Model
// Short Description: Checks the content of the parameter dictionary DLPreprocessParam. 
void check_dl_preprocess_param_ht(HTuple hv_DLPreprocessParam);
// Chapter: Deep Learning / Model
void check_train_dl_model_params_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle,
	HTuple hv_NumTrainSamples, HTuple hv_StartEpoch, HTuple hv_TrainParam);
// Chapter: Deep Learning / Object Detection
// Short Description: This procedure performs k-means clustering on the given parameter values. 
void cluster_dl_detection_param_ht(HTuple hv_Values, HTuple hv_K, HTuple hv_MinRatio,
	HTuple hv_MinDiff, HTuple *hv_ClusteredValues);
// Chapter: Deep Learning / Object Detection
// Short Description: This procedure clusters the given data Points with the specified initial cluster centers InitialClusterCenters. It returns the optimized cluster centers ClusterCenters and the clustered data points PointClusters. 
void cluster_kmeans_1d_ht(HTuple hv_Points, HTuple hv_InitialClusterCenters, HTuple hv_MaxIteration,
	HTuple hv_MinDelta, HTupleVector/*{eTupleVector,Dim=1}*/ *hvec_PointClusters,
	HTuple *hv_ClusterCenters);
// Chapter: Deep Learning / Model
// Short Description: Collect the information required for displaying the training progress update. 
void collect_train_dl_model_info_ht(HTuple hv_DLModelHandle, HTuple hv_TrainResults,
	HTuple hv_EvaluationInfos, HTuple hv_EvaluationComparisonKeys, HTuple hv_Iteration,
	HTuple hv_NumIterations, HTuple hv_NumIterationsPerEpoch, HTuple hv_NumSamplesMeanLoss,
	HTuple *hv_TrainInfo);
// Chapter: Graphics / Parameters
void color_string_to_rgb(HTuple hv_Color, HTuple *hv_RGB);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Compute thresholds for DL Anomaly Detection. 
void compute_dl_anomaly_thresholds_ht(HTuple hv_DLModelHandle, HTuple hv_DLDataset,
	HTuple hv_GenParam, HTuple *hv_AnomalySegmentationThreshold, HTuple *hv_AnomalyClassificationThresholds);
// Chapter: Deep Learning / Classification
// Short Description: Calculate top-K error. 
void compute_top_k_error_ht(HTuple hv_ImageLabelIDs, HTuple hv_TopKPredictions,
	HTuple hv_K, HTuple *hv_TopKError);
// Chapter: Tools / Geometry
// Short Description: Convert the parameters of rectangles with format rectangle2 to the coordinates of its 4 corner-points. 
void convert_rect2_5to8param_ht(HTuple hv_Row, HTuple hv_Col, HTuple hv_Length1,
	HTuple hv_Length2, HTuple hv_Phi, HTuple *hv_Row1, HTuple *hv_Col1, HTuple *hv_Row2,
	HTuple *hv_Col2, HTuple *hv_Row3, HTuple *hv_Col3, HTuple *hv_Row4, HTuple *hv_Col4);
// Chapter: Tools / Geometry
// Short Description: Convert for four-sided figures the coordinates of the 4 corner-points to the parameters of format rectangle2. 
void convert_rect2_8to5param_ht(HTuple hv_Row1, HTuple hv_Col1, HTuple hv_Row2,
	HTuple hv_Col2, HTuple hv_Row3, HTuple hv_Col3, HTuple hv_Row4, HTuple hv_Col4,
	HTuple hv_ForceL1LargerL2, HTuple *hv_Row, HTuple *hv_Col, HTuple *hv_Length1,
	HTuple *hv_Length2, HTuple *hv_Phi);
void create_counting_result_text_ht(HTuple hv_NumberDetectionsPerClass, HTuple hv_ClassNames,
	HTuple *hv_Text, HTuple *hv_TextColor, HTuple *hv_TextBoxColor);
// Chapter: Deep Learning / Model
// Short Description: Creates a dictionary with the preprocessing parameters based on a given DL model. 
void create_dl_preprocess_param_from_model_ht(HTuple hv_DLModelHandle, HTuple hv_NormalizationType,
	HTuple hv_DomainHandling, HTuple hv_SetBackgroundID, HTuple hv_ClassIDsBackground,
	HTuple hv_GenParam, HTuple *hv_DLPreprocessParam);
// Chapter: Deep Learning / Model
// Short Description: Creates a dictionary with preprocessing parameters. 
void create_dl_preprocess_param_ht(HTuple hv_DLModelType, HTuple hv_ImageWidth,
	HTuple hv_ImageHeight, HTuple hv_ImageNumChannels, HTuple hv_ImageRangeMin, HTuple hv_ImageRangeMax,
	HTuple hv_NormalizationType, HTuple hv_DomainHandling, HTuple hv_IgnoreClassIDs,
	HTuple hv_SetBackgroundID, HTuple hv_ClassIDsBackground, HTuple hv_GenParam,
	HTuple *hv_DLPreprocessParam);
// Chapter: Deep Learning / Model
// Short Description: Create a training parameter dictionary which is used in train_dl_model. 
void create_dl_train_param_ht(HTuple hv_DLModelHandle, HTuple hv_NumEpochs, HTuple hv_EvaluationIntervalEpochs,
	HTuple hv_EnableDisplay, HTuple hv_RandomSeed, HTuple hv_GenParamName, HTuple hv_GenParamValue,
	HTuple *hv_TrainParam);
// Chapter: Deep Learning / Evaluation
// Short Description: Generate a dictionary EvalParams, which contains default values for evaluation parameters. 
void create_evaluation_default_param_ht(HTuple hv_EvaluationType, HTuple hv_ClassIDsModel,
	HTuple *hv_EvalParams);
// Chapter: Deep Learning / Object Detection
// Short Description: Analyze the provided DLDataset for object detection to find model parameters relevant for anchor generation. 
void determine_dl_model_detection_param_ht(HTuple hv_DLDataset, HTuple hv_ImageWidthTarget,
	HTuple hv_ImageHeightTarget, HTuple hv_GenParam, HTuple hv_WindowHandles, HTuple *hv_DLDetectionModelParam);
// Chapter: Graphics / Window
// Short Description: Close all window handles contained in a dictionary. 
void dev_close_window_dict(HTuple hv_WindowHandleDict);
// Chapter: Graphics / Output
// Short Description: Display an interactive button. 
void dev_disp_button(HTuple hv_String, HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
	HTuple hv_Height, HTuple hv_ColorString, HTuple hv_ColorBackground, HTuple hv_ColorBackgroundActive,
	HTuple hv_WindowHandle, HTuple *hv_SelectedButton);
// Chapter: Graphics / Output
// Short Description: Display a map of the confidences. 
void dev_display_confidence_regions_ht(HObject ho_ImageConfidence, HTuple hv_DrawTransparency,
	HTuple *hv_Colors);
// Chapter: Deep Learning / Model
// Short Description: Visualize for a given number of samples the raw image, ground truth annotation, and inferred results. 
void dev_display_dl_data_tiled_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle,
	HTuple hv_NumSamples, HTuple hv_Split, HTuple hv_GenParam, HTuple hv_WindowHandle,
	HTuple *hv_WindowHandleOut);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Display the ground truth anomaly regions of the given DLSample. 
void dev_display_ground_truth_anomaly_regions_ht(HTuple hv_SampleKeys, HTuple hv_DLSample,
	HTuple hv_CurrentWindowHandle, HTuple hv_LineWidth, HTuple hv_AnomalyRegionLabelColor,
	HTuple hv_AnomalyColorTransparency, HTuple *hv_AnomalyRegionExists);
// Chapter: Graphics / Output
// Short Description: Display the ground truth bounding boxes of DLSample. 
void dev_display_ground_truth_detection_ht(HTuple hv_DLSample, HTuple hv_SampleKeys,
	HTuple hv_LineWidthBbox, HTuple hv_ClassIDs, HTuple hv_BboxColors, HTuple hv_BboxLabelColor,
	HTuple hv_TextColor, HTuple hv_ShowLabels, HTuple hv_ShowDirection, HTuple hv_WindowHandle,
	HTuple *hv_BboxIDs);
// Chapter: Deep Learning / Model
// Short Description: Initialize the visualization of the training progress. 
void dev_display_init_train_dl_model_ht(HTuple hv_DLModelHandle, HTuple hv_TrainParam,
	HTuple hv_WindowHandle, HTuple *hv_DisplayData);
// Chapter: Graphics / Output
// Short Description: Display a color bar next to an image. 
void dev_display_map_color_bar_ht(HTuple hv_ImageWidth, HTuple hv_ImageHeight, HTuple hv_MapColorBarWidth,
	HTuple hv_Colors, HTuple hv_MaxValue, HTuple hv_WindowImageRatio, HTuple hv_WindowHandle);
// Chapter: Graphics / Output
// Short Description: This procedure draws a pie chart into the active window handle. 
void dev_display_pie_chart(HTuple hv_WindowHandle, HTuple hv_Ratios, HTuple hv_Row,
	HTuple hv_Column, HTuple hv_Radius, HTuple hv_Colors, HTuple hv_GenParam);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Display the detected anomaly regions. 
void dev_display_result_anomaly_regions_ht(HObject ho_AnomalyImage, HObject *ho_AnomalyRegion,
	HTuple hv_CurrentWindowHandle, HTuple hv_AnomalyRegionThreshold, HTuple hv_LineWidth,
	HTuple hv_AnomalyRegionResultColor);
// Chapter: Graphics / Output
// Short Description: Display result bounding boxes. 
void dev_display_result_detection_ht(HTuple hv_DLResult, HTuple hv_ResultKeys, HTuple hv_LineWidthBbox,
	HTuple hv_ClassIDs, HTuple hv_TextConf, HTuple hv_Colors, HTuple hv_BoxLabelColor,
	HTuple hv_WindowImageRatio, HTuple hv_TextPositionRow, HTuple hv_TextColor, HTuple hv_ShowLabels,
	HTuple hv_ShowDirection, HTuple hv_WindowHandle, HTuple *hv_BboxIDs);
// Chapter: Graphics / Output
// Short Description: Display the ground truth/result segmentation as regions. 
void dev_display_segmentation_regions_ht(HObject ho_SegmentationImage, HTuple hv_ClassIDs,
	HTuple hv_ColorsSegmentation, HTuple hv_ExcludeClassIDs, HTuple *hv_ImageClassIDs);
// Chapter: Deep Learning / Model
// Short Description: Display a legend according to the generic parameters. 
void dev_display_tiled_legend_ht(HTuple hv_WindowImages, HTuple hv_GenParam);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Display information about the training of an anomaly detection model. 
void dev_display_train_info_anomaly_detection_ht(HTuple hv_TrainParam, HTuple hv_WindowHandleInfo);
// Chapter: Deep Learning / Model
// Short Description: Update the various texts and plots during training. 
void dev_display_update_train_dl_model_ht(HTuple hv_TrainParam, HTuple hv_DisplayData,
	HTuple hv_TrainInfo, HTuple hv_Epochs, HTuple hv_Loss, HTuple hv_LearningRate,
	HTuple hv_EvalEpochs, HTuple hv_EvalValues, HTuple hv_EvalValuesTrain);
// Chapter: Graphics / Output
// Short Description: Display a map of weights. 
void dev_display_weight_regions_ht(HObject ho_ImageWeight, HTuple hv_DrawTransparency,
	HTuple hv_SegMaxWeight, HTuple *hv_Colors);
// Chapter: Develop
// Short Description: Open a new graphics window that preserves the aspect ratio of the given image size. 
void dev_open_window_fit_size(HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
	HTuple hv_Height, HTuple hv_WidthLimit, HTuple hv_HeightLimit, HTuple *hv_WindowHandle);
// Chapter: Develop
// Short Description: Resizes a graphics window with a given maximum extent such that it preserves the aspect ratio of a given width and height 
void dev_resize_window_fit_size(HTuple hv_Row, HTuple hv_Column, HTuple hv_Width,
	HTuple hv_Height, HTuple hv_WidthLimit, HTuple hv_HeightLimit);
// Chapter: Graphics / Text
// Short Description: This procedure writes a text message. 
void disp_message(HTuple hv_WindowHandle, HTuple hv_String, HTuple hv_CoordSystem,
	HTuple hv_Row, HTuple hv_Column, HTuple hv_Color, HTuple hv_Box);
// Chapter: Time
// Short Description: Estimate the remaining time for a task given the current progress. 
void estimate_progress_ht(HTuple hv_SecondsStart, HTuple hv_ProgressMin, HTuple hv_ProgressCurrent,
	HTuple hv_ProgressMax, HTuple *hv_SecondsElapsed, HTuple *hv_SecondsRemaining,
	HTuple *hv_ProgressPercent, HTuple *hv_ProgressPerSecond);
// Chapter: Deep Learning / Evaluation
// Short Description: Evaluate the model given by DLModelHandle on the selected samples of DLDataset. 
void evaluate_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_SampleSelectMethod,
	HTuple hv_SampleSelectValues, HTuple hv_GenParam, HTuple *hv_EvaluationResult,
	HTuple *hv_EvalParams);
// Chapter: Deep Learning / Model
// Short Description: Retrieve the indices of Samples that contain KeyName matching KeyValue according to the Mode set. 
void find_dl_samples_ht(HTuple hv_Samples, HTuple hv_KeyName, HTuple hv_KeyValue,
	HTuple hv_Mode, HTuple *hv_SampleIndices);
// Chapter: XLD / Creation
// Short Description: Creates an arrow shaped XLD contour. 
void gen_arrow_contour_xld(HObject *ho_Arrow, HTuple hv_Row1, HTuple hv_Column1,
	HTuple hv_Row2, HTuple hv_Column2, HTuple hv_HeadLength, HTuple hv_HeadWidth);
// Chapter: Deep Learning / Model
// Short Description: Create blank train sample dicts for a given model. 
void gen_blank_dl_train_samples_ht(HTuple hv_DLModelHandle, HTuple *hv_TrainSamples);
// Chapter: Deep Learning / Classification
// Short Description: Compute a confusion matrix, which an be visualized and/or returned. 
void gen_confusion_matrix(HTuple hv_GroundTruthLabels, HTuple hv_PredictedClasses,
	HTuple hv_GenParamName, HTuple hv_GenParamValue, HTuple hv_WindowHandle, HTuple *hv_ConfusionMatrix);
// Chapter: Deep Learning / Classification
// Short Description: Return the confidence based heatmap of a deep learning classification in DLResult. 
void gen_dl_model_classification_heatmap(HTuple hv_DLModelHandle, HTuple hv_DLSample,
	HTuple hv_DLResult, HTuple hv_GenParam);
// Chapter: Deep Learning / Model
// Short Description: Store the given images in a tuple of dictionaries DLSamples. 
void gen_dl_samples_from_images(HObject ho_Images, HTuple *hv_DLSampleBatch);
// Chapter: Deep Learning / Model
// Short Description: Store the given images in a tuple of dictionaries DLSamples. 
void gen_dl_samples_from_images_ht(HObject ho_Images, HTuple *hv_DLSampleBatch);
// Chapter: Deep Learning / Model
// Short Description: The procedure returns DLSample dicts for given sample indices of a DLDataset. 
void gen_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple hv_RestrictKeysDLSample,
	HTuple hv_GenParam, HTuple *hv_DLSampleBatch);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Generates weight images for the training dataset. 
void gen_dl_segmentation_weight_images_ht(HTuple hv_DLDataset, HTuple hv_DLPreprocessParam,
	HTuple hv_ClassWeights, HTuple hv_GenParam);
// Chapter: Deep Learning / Classification
// Short Description: Generate a tiled image for the classified DLSamples and add indications whether the predictions are true or not. 
void gen_tiled_classification_image_result_ht(HObject *ho_TiledImageRow, HTuple hv_DLSamples,
	HTuple hv_SpacingCol, HTuple hv_PredictionsCorrect, HTuple hv_ResClasses, HTuple *hv_TextImageRows,
	HTuple *hv_TextImageColumns, HTuple *hv_TextImageWidth, HTuple *hv_TextImageHeight);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Generate a tiled image for segmentation DLSamples. 
void gen_tiled_segmentation_image_ht(HObject *ho_TiledImageRow, HTuple hv_DLSamples,
	HTuple hv_SpacingCol, HTuple hv_Width, HTuple hv_Height);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Get the ground truth anomaly label and label ID. 
void get_anomaly_ground_truth_label_ht(HTuple hv_SampleKeys, HTuple hv_DLSample,
	HTuple *hv_AnomalyLabelGroundTruth, HTuple *hv_AnomalyLabelIDGroundTruth);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Get the anomaly image out of DLResult. 
void get_anomaly_result_ht(HObject *ho_AnomalyImage, HTuple hv_ResultKeys, HTuple hv_DLResult,
	HTuple *hv_AnomalyScore, HTuple *hv_AnomalyClassID);
// Chapter: Graphics / Window
// Short Description: Get the next child window that can be used for visualization. 
void get_child_window_ht(HTuple hv_HeightImage, HTuple hv_Font, HTuple hv_FontSize,
	HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
	HTuple hv_WindowHandleKey, HTuple *hv_WindowImageRatio, HTuple *hv_PrevWindowCoordinatesOut);
// Chapter: Deep Learning / Classification
// Short Description: Get the ground truth classification label id. 
void get_classification_ground_truth_ht(HTuple hv_SampleKeys, HTuple hv_DLSample,
	HTuple *hv_ClassificationLabelIDGroundTruth);
// Chapter: Deep Learning / Classification
// Short Description: Get the predicted classification class ID. 
void get_classification_result_ht(HTuple hv_ResultKeys, HTuple hv_DLResult, HTuple *hv_ClassificationClassID);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Get the confidences of the segmentation result. 
void get_confidence_image_ht(HObject *ho_ImageConfidence, HTuple hv_ResultKeys,
	HTuple hv_DLResult);
// Chapter: Deep Learning / Model
// Short Description: Generate NumColors distinct colors 
void get_distinct_colors_ht(HTuple hv_NumColors, HTuple hv_Random, HTuple hv_StartColor,
	HTuple hv_EndColor, HTuple *hv_Colors);
// Chapter: Deep Learning / Model
// Short Description: Generates certain colors for different ClassNames 
void get_dl_class_colors_ht(HTuple hv_ClassNames, HTuple *hv_Colors);
// Chapter: Deep Learning / Model
// Short Description: Get a parameter value from GenParamValue with the name RequestedGenParamName. 
void get_genparam_single_value_ht(HTuple hv_GenParamName, HTuple hv_GenParamValue,
	HTuple hv_RequestedGenParamName, HTuple *hv_FoundGenParamValue);
// Chapter: Deep Learning / Model
// Short Description: Get the image of a sample. 
void get_image_ht(HObject *ho_Image, HTuple hv_SampleKeys, HTuple hv_DLSample);
// Chapter: Graphics / Window
// Short Description: Get the next window that can be used for visualization. 
void get_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
	HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
	HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
	HTuple hv_WindowHandleKey, HTuple *hv_CurrentWindowHandle, HTuple *hv_WindowImageRatioHeight,
	HTuple *hv_PrevWindowCoordinatesOut);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Get the ground truth segmentation image. 
void get_segmentation_image_ground_truth_ht(HObject *ho_SegmentationImagGroundTruth,
	HTuple hv_SampleKeys, HTuple hv_DLSample);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Get the predicted segmentation result image. 
void get_segmentation_image_result_ht(HObject *ho_SegmentationImageResult, HTuple hv_ResultKeys,
	HTuple hv_DLResult);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Get the weight image of a sample. 
void get_weight_image_ht(HObject *ho_ImageWeight, HTuple hv_SampleKeys, HTuple hv_DLSample);
// Chapter: File / Misc
void images_exist_ht(HTuple hv_ImageList);
// Chapter: Deep Learning / Evaluation
// Short Description: Initialize the dictionary RunningMeasures for the evaluation. 
void init_running_evaluation_measures_ht(HTuple hv_EvalParams, HTuple *hv_RunningMeasures);
// Chapter: Deep Learning / Model
// Short Description: Initialize change strategies data. 
void init_train_dl_model_change_strategies_ht(HTuple hv_TrainParam, HTuple *hv_ChangeStrategyData);
// Chapter: Deep Learning / Model
// Short Description: Initializes the dictionary setting the serialization strategies. 
void init_train_dl_model_serialization_strategies_ht(HTuple hv_TrainParam, HTuple *hv_SerializationData);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Generate image list and corresponding annotation file list. 
void list_image_and_annotation_files_ht(HTuple hv_Type, HTuple hv_ImageDir, HTuple hv_AnnotationDir,
	HTuple hv_ImageListIn, HTuple hv_GenParam, HTuple *hv_ImageListOut, HTuple *hv_LabelListOut,
	HTuple *hv_AnnotationListOut);
// Chapter: Deep Learning / Model
// Short Description: shuffles the input colors in a deterministic way 
void make_neighboring_colors_distinguishable_ht(HTuple hv_ColorsRainbow, HTuple *hv_Colors);
// Chapter: Graphics / Window
// Short Description: Open a window next to the given WindowHandleFather.  
void open_child_window_ht(HTuple hv_WindowHandleFather, HTuple hv_Font, HTuple hv_FontSize,
	HTuple hv_Text, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
	HTuple hv_WindowHandleKey, HTuple *hv_WindowHandleChild, HTuple *hv_PrevWindowCoordinatesOut);
// Chapter: Graphics / Window
// Short Description: Open a new window, either next to the last ones, or in a new row. 
void open_next_window_ht(HTuple hv_Font, HTuple hv_FontSize, HTuple hv_ShowBottomDesc,
	HTuple hv_WidthImage, HTuple hv_HeightImage, HTuple hv_MapColorBarWidth, HTuple hv_ScaleWindows,
	HTuple hv_ThresholdWidth, HTuple hv_PrevWindowCoordinates, HTuple hv_WindowHandleDict,
	HTuple hv_WindowHandleKey, HTuple *hv_WindowHandleNew, HTuple *hv_WindowImageRatioHeight,
	HTuple *hv_PrevWindowCoordinatesOut);
// Chapter: File / Misc
// Short Description: Parse a filename into directory, base filename, and extension 
void parse_filename_ht(HTuple hv_FileName, HTuple *hv_BaseName, HTuple *hv_Extension,
	HTuple *hv_Directory);
// Chapter: Deep Learning / Object Detection
// Short Description: This procedure generates a histogram out of the input and displays the plot. 
void plot_dl_detection_histogram_ht(HTuple hv_DataCollection, HTuple hv_Color, HTuple hv_GenParamName,
	HTuple hv_GenParamValue, HTuple hv_WindowHandle);
// Chapter: Graphics / Output
// Short Description:  This procedure plots tuples representing functions or curves in a coordinate system. 
void plot_tuple_ht(HTuple hv_WindowHandle, HTuple hv_XValues, HTuple hv_YValues,
	HTuple hv_XLabel, HTuple hv_YLabel, HTuple hv_Color, HTuple hv_GenParamName,
	HTuple hv_GenParamValue);
// Chapter: Graphics / Output
// Short Description: This procedure plots tuples representing functions or curves in a coordinate system. 
void plot_tuple_no_window_handling_ht(HTuple hv_WindowHandle, HTuple hv_XValues,
	HTuple hv_YValues, HTuple hv_XLabel, HTuple hv_YLabel, HTuple hv_Color, HTuple hv_GenParamName,
	HTuple hv_GenParamValue);
// Chapter: File / Misc
void prepare_image_lists_ht(HTuple hv_ImageDirs, HTuple hv_Extensions, HTuple *hv_ImageBaseNames,
	HTuple *hv_ImageExtensions, HTuple *hv_ImageDirectories);
// Chapter: Deep Learning / Model
// Short Description: Standard preprocessing on the entire dataset declared in DLDataset. 
void preprocess_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_DataDirectory, HTuple hv_DLPreprocessParam,
	HTuple hv_GenParam, HTuple hv_WindowHandle, HTuple *hv_DLDatasetFileName);
// Chapter: Deep Learning / Model
// Short Description: Preprocess anomaly images for evaluation and visualization of the deep-learning-based anomaly detection. 
void preprocess_dl_model_anomaly_ht(HObject ho_AnomalyImages, HObject *ho_AnomalyImagesPreprocessed,
	HTuple hv_DLPreprocessParam);
// Chapter: Deep Learning / Object Detection
// Short Description: This procedure preprocesses the bounding boxes of type 'rectangle1' for a given sample. 
void preprocess_dl_model_bbox_rect1_ht(HObject ho_ImageRaw, HTuple hv_DLSample,
	HTuple hv_DLPreprocessParam);
// Chapter: Deep Learning / Object Detection
// Short Description: This procedure preprocesses the bounding boxes of type 'rectangle2' for a given sample. 
void preprocess_dl_model_bbox_rect2_ht(HObject ho_ImageRaw, HTuple hv_DLSample,
	HTuple hv_DLPreprocessParam);
// Chapter: Deep Learning / Model
// Short Description: Preprocess images for deep-learning-based training and inference. 
void preprocess_dl_model_images_ht(HObject ho_Images, HObject *ho_ImagesPreprocessed,
	HTuple hv_DLPreprocessParam);
// Chapter: Deep Learning / Semantic Segmentation
// Short Description: Preprocess segmentation and weight images for deep-learning-based segmentation training and inference. 
void preprocess_dl_model_segmentations_ht(HObject ho_ImagesRaw, HObject ho_Segmentations,
	HObject *ho_SegmentationsPreprocessed, HTuple hv_DLPreprocessParam);
// Chapter: Deep Learning / Model
// Short Description: Preprocess given DLSamples according to the preprocessing parameters given in DLPreprocessParam. 
void preprocess_dl_samples_ht(HTuple hv_DLSampleBatch, HTuple hv_DLPreprocessParam);
// Chapter: Tuple / Conversion
// Short Description: Prints a tuple of values to a string. 
void pretty_print_tuple_ht(HTuple hv_Tuple, HTuple *hv_TupleStr);
// Chapter: System / Multithreading
void read_dict_object_ht(HObject *ho_ObjectData, HTuple hv_DictHandle, HTuple hv_Key);
// Chapter: System / Multithreading
void read_dict_tuple_ht(HTuple hv_DictHandle, HTuple hv_Key, HTuple *hv_TupleData);
// Chapter: Image / Manipulation
// Short Description: Changes a value of ValuesToChange in Image to NewValue. 
void reassign_pixel_values_ht(HObject ho_Image, HObject *ho_ImageOut, HTuple hv_ValuesToChange,
	HTuple hv_NewValue);
// Chapter: Deep Learning / Evaluation
// Short Description: Reduce the evaluation result to a single value. 
void reduce_dl_evaluation_result_ht(HTuple hv_EvaluationResult, HTuple hv_EvaluationComparisonKeys,
	HTuple *hv_Value, HTuple *hv_ValidEvaluationKeys);
// Chapter: File / Misc
// Short Description: This procedure removes a directory recursively. 
void remove_dir_recursively_ht(HTuple hv_DirName);
// Chapter: Deep Learning / Object Detection
// Short Description: This procedure removes a given ratio of the smallest and largest data points in the data collection DataCollection. 
void remove_dl_data_outliers_ht(HTuple hv_DataCollection, HTuple *hv_DataCollectionReduced);
// Chapter: Deep Learning / Model
// Short Description: This procedure replaces legacy preprocessing parameters. 
void replace_legacy_preprocessing_parameters_ht(HTuple hv_DLPreprocessParam);
// Chapter: Filters / Arithmetic
// Short Description: Scale the gray values of an image from the interval [Min,Max] to [0,255] 
void scale_image_range(HObject ho_Image, HObject *ho_ImageScaled, HTuple hv_Min,
	HTuple hv_Max);
// Chapter: Deep Learning / Object Detection
// Short Description: This procedure calculates the scaled bounding box parameters for a bounding box of type rectangle2. 
void scale_rectangle2_bbox_ht(HTuple hv_Row, HTuple hv_Col, HTuple hv_Length1, HTuple hv_Length2,
	HTuple hv_Phi, HTuple hv_FactorHeight, HTuple hv_FactorWidth, HTuple *hv_NewRow,
	HTuple *hv_NewCol, HTuple *hv_NewLength1, HTuple *hv_NewLength2, HTuple *hv_NewPhi);
// Chapter: Deep Learning / Object Detection
// Short Description: This procedure suggests the minimum and maximum level as well as the number of anchor subscales for an object detection model. 
void select_dl_detection_levels_ht(HTuple hv_Areas, HTuple hv_MinLevel, HTuple hv_MaxLevel,
	HTuple hv_AnchorNumSubscales, HTuple *hv_MinLevelToUse, HTuple *hv_MaxLevelToUse,
	HTuple *hv_AnchorNumSubscalesToUse);
// Chapter: Deep Learning / Model
// Short Description: Serialize a DLModelHandle with current meta information. 
void serialize_train_dl_model_intermediate_ht(HTuple hv_DLModelHandle, HTuple hv_Epoch,
	HTuple hv_Strategy, HTuple hv_TrainInfos, HTuple hv_EvaluationInfos, HTuple *hv_FilenameModel,
	HTuple *hv_FilenameMetaData);
// Chapter: Graphics / Text
// Short Description: Set font independent of OS 
void set_display_font(HTuple hv_WindowHandle, HTuple hv_Size, HTuple hv_Font, HTuple hv_Bold,
	HTuple hv_Slant);
// Chapter: Deep Learning / Model
// Short Description: Set the model parameters based on preprocessing parameters. 
void set_dl_model_param_based_on_preprocessing_ht(HTuple hv_DLModelHandle, HTuple hv_DLPreprocessParam,
	HTuple hv_ClassIDs);
// Chapter: Deep Learning / Model
// Short Description: Set the maximum batch size for a given DLModelHandle and GPU. 
void set_dl_model_param_max_gpu_batch_size_ht(HTuple hv_DLModelHandle, HTuple hv_BatchSizeUpperBound);
// Chapter: Deep Learning / Model
// Short Description: Split the samples into training, validation, and test subsets. 
void split_dl_dataset_ht(HTuple hv_DLDataset, HTuple hv_TrainingPercent, HTuple hv_ValidationPercent,
	HTuple hv_GenParam);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Apply the given thresholds on anomaly detection results for image classification and region segmentation. 
void threshold_dl_anomaly_results_ht(HTuple hv_AnomalySegmentationThreshold, HTuple hv_AnomalyClassificationThreshold,
	HTuple hv_DLResults);
// Chapter: Time
// Short Description: Create a formatted string of a time span. 
void timespan_string(HTuple hv_TotalSeconds, HTuple hv_Format, HTuple *hv_TimeString);
// Chapter: Deep Learning / Model
// Short Description: Train a deep-learning-based model on a dataset. 
void train_dl_model_ht(HTuple hv_DLDataset, HTuple hv_DLModelHandle, HTuple hv_TrainParam,
	HTuple hv_StartEpoch, HTuple hv_WindowHandles, HTuple *hv_TrainResults, HTuple *hv_TrainInfos,
	HTuple *hv_EvaluationInfos);
// Chapter: Deep Learning / Evaluation
// Short Description: Update RunningMeasures by evaluating Samples and corresponding Results. 
void update_running_evaluation_measures_ht(HTuple hv_Samples, HTuple hv_Results,
	HTuple hv_EvalParams, HTuple hv_RunningMeasures);
// Chapter: Deep Learning / Anomaly Detection
// Short Description: Update running measures for an image anomaly detection evaluation. 
void update_running_image_anomaly_measures_ht(HTuple hv_Samples, HTuple hv_Results,
	HTuple hv_EvalParams, HTuple hv_RunningMeasures);
// Chapter: Deep Learning / Evaluation
// Short Description: Update running measures for an image classification evaluation. 
void update_running_image_classification_measures_ht(HTuple hv_Samples, HTuple hv_Results,
	HTuple hv_EvalParams, HTuple hv_RunningMeasures);
// Chapter: Deep Learning / Evaluation
// Short Description: Update running measures for an instance-based evaluation. 
void update_running_instance_measures_ht(HTuple hv_Samples, HTuple hv_Results, HTuple hv_EvalParams,
	HTuple hv_RunningMeasures);
// Chapter: Deep Learning / Evaluation
// Short Description: Update running measures for a pixel-based evaluation. 
void update_running_pixel_measures_ht(HTuple hv_Samples, HTuple hv_Results, HTuple hv_EvalParams,
	HTuple hv_RunningMeasures);
// Chapter: Deep Learning / Model
// Short Description: Update model parameters according to the change strategies. 
void update_train_dl_model_change_strategies_ht(HTuple hv_DLModelHandle, HTuple hv_ChangeStrategyData,
	HTuple hv_Epoch);
// Chapter: Deep Learning / Model
// Short Description: Serialize the model if a strategy applies to the current training status. 
void update_train_dl_model_serialization_ht(HTuple hv_TrainParam, HTuple hv_SerializationData,
	HTuple hv_Iteration, HTuple hv_NumIterations, HTuple hv_Epoch, HTuple hv_EvaluationResult,
	HTuple hv_DLModelHandle, HTuple hv_TrainInfos, HTuple hv_EvaluationInfos);
// Chapter: Graphics / Window
// Short Description: This procedure sets and returns meta information to display images correctly. 
void update_window_meta_information_ht(HTuple hv_WindowHandle, HTuple hv_WidthImage,
	HTuple hv_HeightImage, HTuple hv_WindowRow1, HTuple hv_WindowColumn1, HTuple hv_MapColorBarWidth,
	HTuple hv_MarginBottom, HTuple *hv_WindowImageRatioHeight, HTuple *hv_WindowImageRatioWidth,
	HTuple *hv_SetPartRow2, HTuple *hv_SetPartColumn2, HTuple *hv_PrevWindowCoordinatesOut);
// Chapter: Deep Learning / Evaluation
// Short Description: Check that all given entries in EvalParams are valid. 
void validate_evaluation_param_ht(HTuple hv_EvalParams, HTuple *hv_Valid, HTuple *hv_Exception);
// Chapter: Deep Learning / Model
// Short Description: Write the dictionaries of the samples in DLSampleBatch to hdict files and store the paths in DLDataset. 
void write_dl_samples_ht(HTuple hv_DLDataset, HTuple hv_SampleIndices, HTuple hv_DLSampleBatch,
	HTuple hv_GenParamName, HTuple hv_GenParamValue);



#endif //__DL_DLL_INTERFACE_H__