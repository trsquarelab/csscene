
#ifndef RBEZIERPARTICLES_H
#define RBEZIERPARTICLES_H

#include "rparticles.h"

namespace chikkooos
{

class RBezierParticles: public RParticles
{
public:

    enum Option
    {
        RandomLifeTime,
        FullLifeTime
    };    

    class RParticle
    {
    public:
        RParticle(float & px, float & py, float & pz, 
                  float & sx, float & sy, float & sz, 
                  float & ex, float & ey, float & ez, 
                  float & cx, float & cy, float & cz, 
                  float & duration, RTime & starttime)
         : mPositionX(px),
           mPositionY(py),
           mPositionZ(pz),
           mStartX(sx),
           mStartY(sy),
           mStartZ(sz),
           mEndX(ex),
           mEndY(ey),
           mEndZ(ez),
           mControlX(cx),
           mControlY(cy),
           mControlZ(cz),
           mDuration(duration),
           mStartTime(starttime)
        {}

        float & mPositionX;
        float & mPositionY;
        float & mPositionZ;
        float & mStartX;
        float & mStartY;
        float & mStartZ;
        float & mEndX;
        float & mEndY;
        float & mEndZ;
        float & mControlX;
        float & mControlY;
        float & mControlZ;
        float & mDuration;
        RTime & mStartTime;
    };

public:
    RBezierParticles(unsigned int count=50)
     : RParticles(count),
       mLifeTimeOption(RandomLifeTime),
       mXEndFrom(0.0f),
       mYEndFrom(0.0f),
       mZEndFrom(0.0f),
       mXEndTo(1.0f),
       mYEndTo(1.0f),
       mZEndTo(1.0f),
       mXControlFrom(-0.5),
       mYControlFrom(0.5),
       mZControlFrom(-0.5),
       mXControlTo(0.5),
       mYControlTo(0.5),
       mZControlTo(0.5)
    {}

    RParticle particle(int index)
    {
        int ai = index * 3;
        return RParticle(mVertices[ai+0], mVertices[ai+1], mVertices[ai+2],
                         mStartVertices[ai+0], mStartVertices[ai+1], mStartVertices[ai+2],
                         mEndVertices[ai+0], mEndVertices[ai+1], mEndVertices[ai+2],
                         mControlVertices[ai+0], mControlVertices[ai+1], mControlVertices[ai+2],
                         mLifeTimes[index], mStartTimes[index]);
    }

    void reset();

    void update(float ms);

    unsigned int count() const
    {
        return mLifeTimes.size();
    }

    const float * vertices() const
    {
        return &(mVertices[0]);
    }
    
    float xEndFrom() const
    {
        return mXEndFrom;
    }

    float xEndTo() const
    {
        return mXEndTo;
    }

    float yEndFrom() const
    {
        return mYEndFrom;
    }

    float yEndTo() const
    {
        return mYEndTo;
    }

    float zEndFrom() const
    {
        return mZEndFrom;
    }

    float zEndTo() const
    {
        return mZEndTo;
    }

    void setXEnd(float from, float to)
    {
        mXEndFrom = from;
        mXEndTo = to;
    }

    void setYEnd(float from, float to)
    {
        mYEndFrom = from;
        mYEndTo = to;
    }

    void setZEnd(float from, float to)
    {
        mZEndFrom = from;
        mZEndTo = to;
    }

    float xControlFrom() const
    {
        return mXControlFrom;
    }

    float xControlTo() const
    {
        return mXControlTo;
    }

    float yControlFrom() const
    {
        return mYControlFrom;
    }

    float yControlTo() const
    {
        return mYControlTo;
    }

    float zControlFrom() const
    {
        return mZControlFrom;
    }

    float zControlTo() const
    {
        return mZControlTo;
    }

    void setXControl(float from, float to)
    {
        mXControlFrom = from;
        mXControlTo = to;
    }

    void setYControl(float from, float to)
    {
        mYControlFrom = from;
        mYControlTo = to;
    }

    void setZControl(float from, float to)
    {
        mZControlFrom = from;
        mZControlTo = to;
    }

    Option lifetimeOption()
    {
        return mLifeTimeOption;
    }

    void setLifetimeOption(Option o)
    {
        mLifeTimeOption = o;
    }

private:
    void remove(int index);
    void add();
    void reset(RParticle & p);

private:
    std::vector<float> mVertices;
    std::vector<float> mEndVertices;
    std::vector<float> mStartVertices;
    std::vector<float> mControlVertices;
    std::vector<float> mLifeTimes;
    std::vector<RTime> mStartTimes;
    Option mLifeTimeOption;
    float mXEndFrom;
    float mYEndFrom;
    float mZEndFrom;
    float mXEndTo;
    float mYEndTo;
    float mZEndTo;
    float mXControlFrom;
    float mYControlFrom;
    float mZControlFrom;
    float mXControlTo;
    float mYControlTo;
    float mZControlTo;
};

}

#endif

