TEMPLATE = app

QT += widgets gui quick multimedia bluetooth
CONFIG += c++11

FORMS += \
    deformwin.ui

HEADERS += \
    deformwin.h \
    myimage.h \
    pointspaint.h \
    projfile.h \
    singlephotoview.h \
    ../lib/delaunay.h \
    ../lib/imgwarp_mls.h \
    ../lib/imgwarp_mls_rigid.h \
    ../lib/imgwarp_mls_similarity.h \
    ../lib/imgwarp_piecewiseaffine.h

SOURCES += \
    deformwin.cpp \
    main.cpp \
    myimage.cpp \
    pointspaint.cpp \
    projfile.cpp \
    singlephotoview.cpp \
    ../lib/delaunay.cpp \
    ../lib/imgwarp_mls.cpp \
    ../lib/imgwarp_mls_rigid.cpp \
    ../lib/imgwarp_mls_similarity.cpp \
    ../lib/imgwarp_piecewiseaffine.cpp


# opencv win and android g++ config 2016-2-29
win32 {
    INCLUDEPATH += D:/WorkPlaceLibrary/includeCVextra
    message("win32 configuration")
    LIBS += -L"D:/WorkPlaceLibrary/lib/opencv/windows/"

    LIBS += -lopencv_core300.dll            \
            -lopencv_face300.dll            \
            -lopencv_hal300                 \
            -lopencv_highgui300.dll         \
            -lopencv_imgcodecs300.dll       \
            -lopencv_imgproc300.dll         \
            -lopencv_ml300.dll              \
            -lopencv_objdetect300.dll       \
            -lopencv_video300.dll           \
            -lopencv_videoio300.dll         \
}

android {
    INCLUDEPATH += D:/WorkPlaceLibrary/include
    message("android configuration")
    LIBS += -L"D:/WorkPlaceLibrary/lib/opencv/armeabi-v7a/"
    LIBS += \
           -lopencv_androidcamera    \
           -lopencv_core             \
           -lopencv_highgui          \
           -lopencv_imgproc          \
           -lopencv_info             \
           -lopencv_java             \
           -lopencv_video            \
           -lopencv_videostab        \
           -ltbb

    contains(ANDROID_TARGET_ARCH,armeabi-v7a) {
        ANDROID_EXTRA_LIBS = \
        D:/WorkPlaceLibrary/lib/opencv/armeabi-v7a/libopencv_info.so \
        D:/WorkPlaceLibrary/lib/opencv/armeabi-v7a/libopencv_java.so    \
        D:/WorkPlaceLibrary/lib/caffe/armeabi-v7a/libcaffe.so
    }

}
#------------- end opencv ------------------------
