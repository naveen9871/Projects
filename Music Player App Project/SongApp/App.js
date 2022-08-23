import * as React from 'react';
import { View, Text , Button, Image, Dimensions, StyleSheet} from 'react-native';
import { NavigationContainer } from '@react-navigation/native';
import { createStackNavigator } from '@react-navigation/stack';
import BollyScreen from './src/BollyScreen';
import AppTolly from './src/tollyscreen';




function HomeScreen({ navigation }) {
  return (
    <View style={{ flex:1 , backgroundColor : "#8a2be2" , justifyContent: 'center',alignItems: 'center'}}>
      <View style={styles.header}>
        <Image 
        source={require('./src/haa.png')} 
        style ={{ width: height_logo , height: height_logo}} 
        resizeMode="stretch"         />
      </View>
      <View style={styles.middle}>
         <Text style={{ color: '#000000',fontSize: 30,fontWeight: 'bold'}}>
          Select Your Language </Text>
      </View>
      
      <Button
        style={styles.button}
        title="Hindi"
        onPress={() => navigation.navigate('Bollywood')}
        color = '#ffa500'
      />
      <View style={styles.space} /> 
      <Button
       title="Telugu"
       onPress={() => navigation.navigate('Tollywood')}
       style={styles.button}
      />
      

    </View>
  );
}

const styles = StyleSheet.create({
  container: { 
    flex:1 , 
    backgroundColor : "#009387"},

  header:{ 
    justifyContent: 'center', 
    alignItems:'center' ,
    flex: 0.3,
    
    borderTopLeftRadius: 20,
    borderTopRightRadius: 20
  },
  middle:{
    flex: 0.3,
    justifyContent: 'center', 
    alignItems:'center'
  

  },

  footer:{ 
    flex:1 ,
    backgroundColor: '#fff',
    borderTopLeftRadius: 30,
    borderTopRightRadius: 30,
    paddingVertical: 50,
    paddingHorizontal: 30},
  
  button: {
    marginBottom: 20,
    padding: 30
    },
  space: {
    width: 20, 
    height: 20,
    }
})

const {height} = Dimensions.get('screen');
const height_logo = height * 0.28; 

const Stack = createStackNavigator();

function App() {
  return (
    <NavigationContainer>
      <Stack.Navigator screenOptions={{
        headerStyle:{
          backgroundColor:'#009387', 

        },
        headerTintColor:'#fff',
        headerTitleStyle: {
          fontWeight:'bold'
        }
      }}>
        <Stack.Screen name="Home" component={HomeScreen}  options={{
          title: 'My Music'}}/>
        <Stack.Screen name="Bollywood" component={BollyScreen} options={{
          title: 'Hindi Songs'}} />
        <Stack.Screen name="Tollywood" component={AppTolly}  options={{
          title: 'Telugu Songs'}}/>
      </Stack.Navigator>
    </NavigationContainer>
  );
}

export default App;