namespace ExplicitInstantiationDefinitionMethod {
class QVncScreen;
class QVncDirtyMap
{
public:
    QVncDirtyMap(QVncScreen *screen) {}
    virtual ~QVncDirtyMap();
    virtual void setDirty(int x, int y, bool force = false) = 0;
    QVncScreen *screen;
};

template <class T>
class QVncDirtyMapOptimized : public QVncDirtyMap
{
public:
    QVncDirtyMapOptimized(QVncScreen *screen) : QVncDirtyMap(screen) {}
    ~QVncDirtyMapOptimized() {}
    void setDirty(int x, int y, bool force = false) override;
};

template <class T>
void QVncDirtyMapOptimized<T>::setDirty(int x, int y, bool force) {

}

template class QVncDirtyMapOptimized<unsigned char>;
template class QVncDirtyMapOptimized<unsigned short>;
template class QVncDirtyMapOptimized<unsigned int>;

}
